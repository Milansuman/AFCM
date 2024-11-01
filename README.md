# AFCM - Advanced File Carving Methods for BTRFS and XFS

## Lab Setup

Install the required dependencies
```sh
sudo apt install btrfs-progs #on Ubuntu
```

Run the following commands **ONLY ONCE**
```sh
cd disks
sh build.sh
```
This will set up a virtual hard drive with a btrfs partition for research. The script will tell you which device it has created the partition at like so:
`The new virtual disk is at /dev/loop0p1`. This will be different depending on your setup.

To access the partition, first mount the partition
```sh
sudo mkdir /mnt/ACFM-tests
mount /dev/loop0p1 /mnt/ACFM-tests #replace with the correct partition
cd /mnt/ACFM-tests
```

If you have already built the btrfs-test.iso file but don't see the loopback device, run
```sh
sh loopback.sh
```
in the disks directory.

## Build

Ensure meson is installed. Then set up the build directory like so:
```sh
mkdir build
meson setup build
cd build && meson compile
```
