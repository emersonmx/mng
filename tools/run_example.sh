#!/usr/bin/env bash
set -euo pipefail
IFS=$'\n\t'

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
PROJECT_ROOT="$SCRIPT_DIR/.."

export LD_LIBRARY_PATH="$PROJECT_ROOT/build/src/mng/"

if [ $# != 1 ]
then
    echo "Usage: $0 <example>"
    exit
fi

(cd "$PROJECT_ROOT/examples/$1" && "$PROJECT_ROOT/build/examples/$1/$1")
