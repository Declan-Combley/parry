#!/bin/sh

set -x

FLAGS="-Wall -Wextra"

gcc -o parry main.c $FLAGS
