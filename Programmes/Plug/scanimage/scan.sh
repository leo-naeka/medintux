#!/bin/bash
# file : scan.sh
DEVICE=$1
DEV_COMMAND=$2
FILE_OUT=$3
scanimage --device-name="$DEVICE" $DEV_COMMAND --format=tiff>"$FILE_OUT"".tiff"
convert "$FILE_OUT"".tiff" "$FILE_OUT"".png"