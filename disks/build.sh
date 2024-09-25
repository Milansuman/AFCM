#!/bin/bash

touch btrfs-test.iso
sudo dd if=/dev/zero of=btrfs-test.iso bs=1MiB count=$((1024*2)) status=progress
sfdisk btrfs-test.iso < btrfs-test.dump

before=$(losetup -l --output NAME --noheadings)
sudo losetup -fP ./btrfs-test.iso
after=$(losetup -l --output NAME --noheadings)

new_device=$(comm -13 <(echo "$before" | sort) <(echo "$after" | sort))
new_device=$(echo $new_device | xargs)

sudo mkfs.btrfs "${new_device}p1"

echo "The new virtual disk is at ${new_device}p1"