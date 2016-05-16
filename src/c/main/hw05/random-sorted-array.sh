#!/bin/bash

ARRAY_MAX_SIZE=19
ARRAY_MAX_MIN_VALUE=19
ARRAY_MAX_MAX_VALUE=20

declare -a ARGS
let "ARGS[0]=($RANDOM%$ARRAY_MAX_SIZE)+1"
let "ARGS[1]=$RANDOM%$ARRAY_MAX_MIN_VALUE"
let "ARGS[2]=${ARGS[1]}+1+$RANDOM%($ARRAY_MAX_MAX_VALUE-${ARGS[1]}-1)"

./array-generate ${ARGS[0]} ${ARGS[1]} ${ARGS[2]} | xargs ./array-sort
