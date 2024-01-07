#!/usr/bin/env bash

# Copy a run script to the images directory and tar the needed files into a
# single package that can be distributed to users.
cp $BR2_EXTERNAL_BOMB_DEFUSAL_PATH/board/bomb-board/run_script.sh $BINARIES_DIR


repo_root=$BASE_DIR/../..
mkdir -p $repo_root/bomb-game
cp $BINARIES_DIR/* $repo_root/bomb-game
cd $repo_root
tar -czf bomb-game.tar.gz bomb-game
