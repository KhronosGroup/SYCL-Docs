#! /bin/bash -vx

# Update the Docker image and run a command for a given user/group


apt install sudo

# To allow the bash configuration to be read by another user
chmod 755 /root

# Update obsolete Docker image to latest gems
gem update

# This one is completely missing from the Docker image
gem install text-hyphen

# Install latest ruby rouge with SYCL support from Git
cd  /tmp
git clone --branch sycl https://github.com/keryell/rouge.git
cd rouge
gem build rouge.gemspec
gem install ./rouge-3.26.0.gem

# Execute as the original user, preserve the PATH explicitly for the gem bundle
sudo --preserve-env --user \#$USER_ID --group \#$GROUP_ID PATH=$PATH $*
