#!/usr/bin/env bash

# configure bash environment
set -o errexit -o pipefail -o noclobber -o nounset

# show usage
show_usage () {
    cat << EOF
usage: $(basename "$0") [ build ] [ stage] [ deploy ]
  -h, --help            shows this message

  build                 builds course materials
  stage                 prepares build artifacts
  deploy                deploys build artifacts to production server
EOF
}

DIR_CONFIG="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
DIR_PROJECT_ROOT="$(dirname "${DIR_CONFIG}")"
DIR_BUILD="${DIR_PROJECT_ROOT}/bin"

build_files () {
    local course_name="umb-cs240-2016s"
    local docker_image="ghorbanzade/${course_name}"
    local docker_container="${course_name}"

    if ! hash "docker" 2>/dev/null; then
        echo "docker is not installed"
        return 1
    fi

    if [ -d "${DIR_BUILD}" ]; then
        echo "build directory already exists"
        return 1
    fi

    docker build -t "${docker_image}" -f "${DIR_CONFIG}/Dockerfile" "${DIR_PROJECT_ROOT}"
    docker create --name "${docker_container}" "${docker_image}":latest
    docker cp "${docker_container}":/opt/bin "${DIR_BUILD}"
    docker stop "${docker_container}"
    docker rm "${docker_container}"
    docker image prune --force --filter label=stage=intermediate
}

stage_files () {
    local line=''
    local dir_src="${DIR_BUILD}/doc"
    local dir_dst="${DIR_BUILD}/tmp"
    local course_name="CS240-2016S"

    if [ ! -d "${DIR_BUILD}" ]; then
        echo "build directory does not exist"
        return 1
    fi

    rm -rf "${dir_dst:?}/${course_name}"
    mkdir -p "${dir_dst:?}/${course_name}"

    while IFS='' read -r line || [[ -n "$line" ]]; do
        if [ -n "$line" ] && [ "${line::1}" != '#' ]; then
            read -r -a line <<< "$line"
            if [ ${#line[@]} -eq 2 ]; then
                src_file=${line[0]}
                dst_file=${line[1]}
            else
                src_file=${line[0]}
                dst_file=${line[0]}
            fi
            cp "${dir_src:?}/${src_file}" "${dir_dst:?}/${course_name:?}/${dst_file}"
        fi
    done < "${DIR_CONFIG}/remote-files.list"
}

upload_to_remote () {
    local dir_dst="${DIR_BUILD}/tmp"
    local course_name="CS240-2016S"
    local file_artifact="${DIR_BUILD}/${course_name}.tar.gz"

    if [ ! -d "${dir_dst}" ]; then
        echo "artifacts directory does not exist"
        return 1
    fi

    if [ -z "${DEPLOY_TARGET}" ]; then
        echo "environment variable DEPLOY_TARGET not set"
        return 1
    fi

    tar -zcf "${file_artifact}" -C "${dir_dst}" "${course_name}"

    scp "${file_artifact}" "${DEPLOY_TARGET}:/tmp/${course_name}.tar.gz"
    # shellcheck disable=SC2029
    ssh "${DEPLOY_TARGET}" "./ghorcom/deploy.sh ${course_name}"
}

# check command line arguments

ARG_HELP=1
ARG_BUILD=0
ARG_STAGE=0
ARG_DEPLOY=0

for arg in "$@"; do
    case $arg in
        "build")
            ARG_BUILD=1
            ARG_HELP=0
            ;;
        "deploy")
            ARG_DEPLOY=1
            ARG_HELP=0
            ;;
        "stage")
            ARG_STAGE=1
            ARG_HELP=0
            ;;
    esac
done

if [[ ${ARG_HELP} -eq 1 ]]; then
    show_usage
    exit 0
fi

if [[ ${ARG_BUILD} -eq 1 ]] && ! build_files; then
    echo "aborting: failing to build course materials"
    exit 1
fi

if [[ ${ARG_STAGE} -eq 1 ]] && ! stage_files; then
    echo "aborting: failed to prepare artifacts"
    exit 1
fi

if [[ ${ARG_DEPLOY} -eq 1 ]] && ! upload_to_remote; then
    echo "aborting: failed to upload artifacts to remote repository"
    exit 1
fi
