#!/bin/bash

SRC_DIR="bin/doc"
DST_DIR="bin/tmp"
COURSE_NAME="CS240-2016S"
COURSE_DIR="${DST_DIR}/${COURSE_NAME}"
STAGING_FILE="bin/${COURSE_NAME}.tar.gz"

upload_to_remote () {
  if [ -z ${DEPLOY_TARGET} ]; then
    echo "aborting: DEPLOY_TARGET not set"
    return 1
  fi

  tar -zcf "${STAGING_FILE}" -C "${DST_DIR}" "${COURSE_NAME}"
  scp "${STAGING_FILE}" "${DEPLOY_TARGET}:/tmp/${COURSE_NAME}.tar.gz"
  ssh ${DEPLOY_TARGET} "./deploy.sh ${COURSE_NAME}"

  rm -rf "${DST_DIR}"
  rm -rf "${STAGING_FILE}"
  return 0
}

stage_files () {
  local ret=0
  local line=''

  if [ ! -d ${SRC_DIR} ]; then
    make clean
    make
  fi
  rm -rf ${COURSE_DIR}
  mkdir -p ${COURSE_DIR}

  while IFS='' read -r line || [[ -n "$line" ]]; do
    if [ ! -z "$line" ] && [ ${line::1} != '#' ]; then
      line=($line)
      if [ ${#line[@]} == 2 ]; then
        src_file=${line[0]}
        dst_file=${line[1]}
      else
        src_file=${line}
        dst_file=${line}
      fi
      cp "${SRC_DIR}/${src_file}" "${COURSE_DIR}/${dst_file}"
      if [ $? -ne 0 ]; then
        ret=1;
      fi
    fi
  done < "$1"
  return ${ret}
}

stage_files cfg/remote-files.list
if [ $? -ne 0 ]; then
  echo "aborting: failed to prepare seed"
  exit 1
fi
upload_to_remote
if [ $? -ne 0 ]; then
  echo "aborting: failed to upload seed to remote"
  exit 1
fi
exit 0
