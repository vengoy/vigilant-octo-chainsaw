#!/bin/bash

WHITE='\033[97m'		#	${WHITE}		
RED='\033[91m'			#	${RED}			
GREEN='\033[92m'		#	${GREEN}		
BLUE='\033[94m'			#	${BLUE}			
PURPLE='\033[95m'       #	${PURPLE}		
BLACK='\033[30m'		#	${BLACK}		

BGWHITE='\033[107m'		#	${BGWHITE}
BGRED='\033[101m'		#	${BGRED}
BGGREEN='\033[102m'		#	${BGGREEN}
BGBLUE='\033[104m'		#	${BGBLUE}
BGPURPLE='\033[105m'	#	${BGPURPLE}
BGBLACK='\033[40m'		#	${BGBLACK}
NORMAL='\e[0m'

argv[0]=$1
argv[1]=$2
argv[2]=$3
argv[3]=$4

for i in 0 2 
do
if [[ ${argv[$i]} -eq 1 ]]
    then 
    PARAMETER[i]=$BGWHITE
fi

if [[ ${argv[$i]} -eq 2 ]]
    then 
    PARAMETER[i]=$BGRED
fi

if [[ ${argv[$i]} -eq 3 ]]
    then 
    PARAMETER[i]=$BGGREEN
fi

if [[ ${argv[$i]} -eq 4 ]]
    then 
    PARAMETER[i]=$BGBLUE
fi

if [[ ${argv[$i]} -eq 5 ]]
    then 
    PARAMETER[i]=$BGPURPLE
fi

if [[ ${argv[$i]} -eq 6 ]]
    then 
    PARAMETER[i]=$BGBLACK
fi
done

for i in 1 3
do
if [[ ${argv[$i]} -eq 1 ]]
    then 
    PARAMETER[i]=$WHITE
fi

if [[ ${argv[$i]} -eq 2 ]]
    then 
    PARAMETER[i]=$RED
fi

if [[ ${argv[$i]} -eq 3 ]]
    then 
    PARAMETER[i]=$GREEN
fi

if [[ ${argv[$i]} -eq 4 ]]
    then 
    PARAMETER[i]=$BLUE
fi

if [[ ${argv[$i]} -eq 5 ]]
    then 
    PARAMETER[i]=$PURPLE
fi

if [[ ${argv[$i]} -eq 6 ]]
    then 
    PARAMETER[i]=$BLACK
fi
done

# Set default
if [[ ${argv[0]} == "" ]]
    then
    PARAMETER[0]=$BGBLACK
fi

if [[ ${argv[1]} == "" ]]
    then
    PARAMETER[1]=$GREEN
fi

if [[ ${argv[2]} == "" ]]
    then
    PARAMETER[2]=$BGBLACK
fi

if [[ ${argv[3]} == "" ]]
    then
    PARAMETER[3]=$PURPLE
fi