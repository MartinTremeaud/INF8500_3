#!/bin/bash -xe
#
# $1 is simulation
# $2 project directory
#
IS_SIMULATION="${1}"
SS_PRJ_DIR="${2}"

# copy image into filesystem
cp $SS_PRJ_DIR/images/image_in.mem ./root

# execute auto_mount when linux boots
if [ $IS_SIMULATION = false ]; then
	SCRIPTS_DIR="$SS_PRJ_DIR/scripts"
	AUTO_MOUNT_FILE="$SCRIPTS_DIR/auto_mount.sh"
	BASE_DESTINATION=./etc/init.d/S100auto_mount.sh

	cp "$AUTO_MOUNT_FILE" "$BASE_DESTINATION"
	chmod +r,u+x "${BASE_DESTINATION}"
fi