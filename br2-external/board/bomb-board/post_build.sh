#!/usr/bin/env bash

# Remove the network setup script. I don't know if there's an option to
# prevent this from being generated in the first place, but I haven't
# found it if it's there.
network_init_file=$1/etc/init.d/S40network
if [ -f "$network_init_file" ]; then
    rm $network_init_file
fi
