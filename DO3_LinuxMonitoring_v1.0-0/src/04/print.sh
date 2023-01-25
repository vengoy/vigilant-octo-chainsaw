#!/bin/bash

source set_color_value.sh $1 $2 $3 $4

HOSTNAME=$(hostname)
timedatectl set-timezone Europe/Moscow
TIMEZONE="$(cat /etc/timezone) $(date -u "+%Z") $(date "+%z")"
USER=$(whoami)
OS=$(cat /etc/issue | awk '{print $1,$2,$3}' | tr -s '\r\n' ' ')
DATE=$(date "+%d %b %Y %H:%M:%S")
UPTIME=$(uptime -p)
UPTIME_SEC=$(cat /proc/uptime | awk '{print $1}')
IP=$(hostname -I | awk '{print $1}')
MASK=$(ifconfig | grep -m1 netmask | awk '{print $4}')
GATEWAY=$(ip r | grep default | awk '{print $3}')
RAM_TOTAL=$(free -m | awk '/Mem:/{printf "%.3f GB", $2/1024}')
RAM_USED=$(free -m | awk '/Mem:/{printf "%.3f GB", $3/1024}')
RAM_FREE=$(free -m | awk '/Mem:/{printf "%.3f GB", $4/1024}')
SPACE_ROOT=$(df /root/ | awk '/\/$/ {printf "%.2f MB", $2/1024}')
SPACE_ROOT_USED=$(df /root/ | awk '/\/$/ {printf "%.2f MB", $3/1024}')
SPACE_ROOT_FREE=$(df /root/ | awk '/\/$/ {printf "%.2f MB", $4/1024}')

echo -e "${PARAMETER[0]}${PARAMETER[1]}HOSTNAME = ${NORMAL}${PARAMETER[2]}${PARAMETER[3]}$HOSTNAME${NORMAL}"
echo -e "${PARAMETER[0]}${PARAMETER[1]}TIMEZONE = ${NORMAL}${PARAMETER[2]}${PARAMETER[3]}$TIMEZONE${NORMAL}"
echo -e "${PARAMETER[0]}${PARAMETER[1]}USER = ${NORMAL}${PARAMETER[2]}${PARAMETER[3]}$USER${NORMAL}"
echo -e "${PARAMETER[0]}${PARAMETER[1]}OS = ${NORMAL}${PARAMETER[2]}${PARAMETER[3]}$OS${NORMAL}"
echo -e "${PARAMETER[0]}${PARAMETER[1]}DATE = ${NORMAL}${PARAMETER[2]}${PARAMETER[3]}$DATE${NORMAL}"
echo -e "${PARAMETER[0]}${PARAMETER[1]}UPTIME = ${NORMAL}${PARAMETER[2]}${PARAMETER[3]}$UPTIME${NORMAL}"
echo -e "${PARAMETER[0]}${PARAMETER[1]}UPTIME_SEC = ${NORMAL}${PARAMETER[2]}${PARAMETER[3]}$UPTIME_SEC${NORMAL}"
echo -e "${PARAMETER[0]}${PARAMETER[1]}IP = ${NORMAL}${PARAMETER[2]}${PARAMETER[3]}$IP${NORMAL}"
echo -e "${PARAMETER[0]}${PARAMETER[1]}MASK = ${NORMAL}${PARAMETER[2]}${PARAMETER[3]}$MASK${NORMAL}"
echo -e "${PARAMETER[0]}${PARAMETER[1]}GATEWAY = ${NORMAL}${PARAMETER[2]}${PARAMETER[3]}$GATEWAY${NORMAL}"
echo -e "${PARAMETER[0]}${PARAMETER[1]}RAM_TOTAL = ${NORMAL}${PARAMETER[2]}${PARAMETER[3]}$RAM_TOTAL${NORMAL}"
echo -e "${PARAMETER[0]}${PARAMETER[1]}RAM_USED = ${NORMAL}${PARAMETER[2]}${PARAMETER[3]}$RAM_USED${NORMAL}"
echo -e "${PARAMETER[0]}${PARAMETER[1]}RAM_FREE = ${NORMAL}${PARAMETER[2]}${PARAMETER[3]}$RAM_FREE${NORMAL}"
echo -e "${PARAMETER[0]}${PARAMETER[1]}SPACE_ROOT = ${NORMAL}${PARAMETER[2]}${PARAMETER[3]}$SPACE_ROOT${NORMAL}"
echo -e "${PARAMETER[0]}${PARAMETER[1]}SPACE_ROOT_USED = ${NORMAL}${PARAMETER[2]}${PARAMETER[3]}$SPACE_ROOT_USED${NORMAL}"
echo -e "${PARAMETER[0]}${PARAMETER[1]}SPACE_ROOT_FREE = ${NORMAL}${PARAMETER[2]}${PARAMETER[3]}$SPACE_ROOT_FREE${NORMAL}"