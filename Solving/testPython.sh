#!/bin/bash
RED='\e[1;31m'
GREEN='\e[1;32m'
WHITE='\e[0m'
CYAN='\e[1;36m'
YELLOW='\e[1;33m'
BOLD='\033[1m'
PLAIN='\033[0m'
time timeout 3 python3 $1 < in.txt > out.txt
if [ $? -eq 124 ]
  then
  echo -e "\n${RED}Error:${WHITE} Time limit exceeded.\n"
  exit 1
fi