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