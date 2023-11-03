#!/bin/bash

# Prompt the user to choose the destination for the include directory
echo "Choose the destination for the include directory:"
echo "1. usr/include"
echo "2. /include"
echo "3. /data/data/com.termux/files/usr/include/"
read -p "Enter your choice (1, 2, or 3): " choice

# Set the destination directory based on the user's choice
if [ $choice -eq 1 ]; then
    destination_dir="/usr/include/"
elif [ $choice -eq 2 ]; then
    destination_dir="/include/"
elif [ $choice -eq 3 ]; then
    destination_dir="/data/data/com.termux/files/usr/include/"
else
    echo "Invalid choice. Exiting..."
    exit 1
fi

# Create the destination directory if it doesn't exist
mkdir -p $destination_dir

# Create a temporary directory
mkdir eigen_temp
cd eigen_temp

# Download the latest stable release of Eigen
wget https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.tar.gz

# Extract the downloaded tarball
tar -xzf eigen-3.4.0.tar.gz

# Rename the extracted directory to "eigen"
mv eigen-3.4.0 eigen

# Move the "eigen" directory to the destination directory
mv eigen $destination_dir

# Clean up the temporary directory
cd ..
rm -rf eigen_temp

echo "Eigen library has been installed in $destination_dir"