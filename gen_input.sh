#!/bin/sh -e

DIR="$1"
NAME="$2"

TOTAL=`find "$DIR" -name "$NAME" | wc -l`
NUMBERS=`find "$DIR" -name "$NAME" -exec wc -l {} \; | awk '{ print $1 }'`

printf "%s\n%s\n" $TOTAL $NUMBERS
