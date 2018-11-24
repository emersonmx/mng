#!/usr/bin/env bash
set -euo pipefail
IFS=$'\n\t'

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

export LD_LIBRARY_PATH="$SCRIPT_DIR/build/src/mng/"

if [ $# != 1 ]
then
    echo "Usage: $0 <example>"
    exit
fi

(cd "$SCRIPT_DIR/examples/$1" && "$SCRIPT_DIR/build/examples/$1/$1")
