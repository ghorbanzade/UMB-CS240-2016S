#!/bin/bash

DIR_CONFIG="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
DIR_PROJECT_ROOT="$(dirname "${DIR_CONFIG}")"

upload_to_remote () {
  local dir_dst="${DIR_PROJECT_ROOT}/bin/tmp"
  local course_name="CS240-2016S"
  local file_artifact="${DIR_PROJECT_ROOT}/bin/${course_name}.tar.gz"

  if [ -z "${DEPLOY_TARGET}" ]; then
    echo "aborting: environment variable DEPLOY_TARGET not set"
    return 1
  fi
  scp "${file_artifact}" "${DEPLOY_TARGET}:/tmp/${course_name}.tar.gz"
  # shellcheck disable=SC2029
  ssh "${DEPLOY_TARGET}" "./ghorcom/deploy.sh ${course_name}"

  rm -rf "${dir_dst}"
  rm -rf "${file_artifact}"
  return 0
}

stage_files () {
  local line=''
  local dir_src="${DIR_PROJECT_ROOT}/bin/doc"
  local dir_dst="${DIR_PROJECT_ROOT}/bin/tmp"
  local course_name="CS240-2016S"
  local file_artifact="${DIR_PROJECT_ROOT}/bin/${course_name}.tar.gz"

  if [ ! -d "${dir_src}" ]; then
    make clean
    make
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
  done < "$1"
  tar -zcf "${file_artifact}" -C "${dir_dst}" "${course_name}"
  rm -rf "${dir_dst:?}"
}

if ! stage_files "${DIR_CONFIG}/remote-files.list"; then
  echo "aborting: failed to prepare artifacts"
  exit 1
fi

if ! upload_to_remote; then
  echo "aborting: failed to upload artifacts to remote repository"
  exit 1
fi

exit 0
