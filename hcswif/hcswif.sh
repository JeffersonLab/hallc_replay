#!/usr/bin/bash
ARGC=$#
if [[ $ARGC -ne 3 ]]; then
    echo Usage: hcswif.sh SCRIPT RUN EVENTS
    exit 1
fi;
script=$1
run=$2
evt=$3

# Setup environment
hcswif_dir=$(dirname $(readlink -f $0))
source $hcswif_dir/setup.sh

# Check environment
# Not sure how best to do this. How do we make sure hcana is in the path?
if [ -z "$(which hcana)" ]; then
    echo Environment not set up! Please edit $hcswif_dir/setup.sh appropriately
    exit 1
fi

# Replay the run
runHcana="./hcana \"$script($run,$evt)\""
cd $hallc_replay_dir
echo pwd: $(pwd)
echo $runHcana
eval $runHcana
