#!/usr/bin/env bash

# Remove the network setup script. I don't know if there's an option to
# prevent this from being generated in the first place, but I haven't
# found it if it's there.
rm $1/etc/init.d/S40network
