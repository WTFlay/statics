#!/bin/bash -e

DIR="$1"
NAME="$2"

cat <(find "$DIR" -name "$NAME" | wc -l) <(find "$DIR" -name "$NAME" -exec wc -l {} \; | awk '{ print $1 }')
