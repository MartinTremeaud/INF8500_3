#!/bin/bash -xe

SD_DEVICE=$(find /dev/mmc*p1 | head -n 1)

mkdir -p /root/sdcard
mount -t vfat "$SD_DEVICE" /root/sdcard/