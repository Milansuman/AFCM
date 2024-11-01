before=$(losetup -l --output NAME --noheadings)
sudo losetup -fP ./btrfs-test.iso
after=$(losetup -l --output NAME --noheadings)

new_device=$(comm -13 <(echo "$before" | sort) <(echo "$after" | sort))
new_device=$(echo $new_device | xargs)

echo "The virtual disk is at ${new_device}p1"