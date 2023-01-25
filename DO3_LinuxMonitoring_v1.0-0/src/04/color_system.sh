#!/bin/bash

source config.conf

# (1 - white, 2 - red, 3 - green, 4 - blue, 5 – purple, 6 - black)
color[0]=$column1_background
color[1]=$column1_font_color
color[2]=$column2_background
color[3]=$column2_font_color

for (( i = 0 ; i < 4 ; i++ ))
do 
    if [[ ${color[$i]} == "" ]]
        then
        argv[$i]="default"
    else
        argv[$i]=${color[$i]}
    fi
done

for (( i = 0 ; i < 4 ; i++ ))
do 
    if [[ ${argv[$i]} == 1 ]]
        then
        color_text[$i]="white"
    fi
    if [[ ${argv[$i]} == 2 ]]
        then
        color_text[$i]="red"
    fi
    if [[ ${argv[$i]} == 3 ]]
        then
        color_text[$i]="green"
    fi
    if [[ ${argv[$i]} == 4 ]]
        then
        color_text[$i]="blue"
    fi
    if [[ ${argv[$i]} == 5 ]]
        then
        color_text[$i]="purple"
    fi
    if [[ ${argv[$i]} == 6 ]]
        then
        color_text[$i]="black"
    fi
done

# default color text
if [[ $column1_background == "" ]]
    then
    color_text[0]="black"
fi

if [[ $column1_font_color == "" ]]
    then
    color_text[1]="green"
fi

if [[ $column2_background == "" ]]
    then
    color_text[2]="black"
fi

if [[ $column2_font_color == "" ]]
    then
    color_text[3]="purple"
fi


echo -e "\nColumn 1 background = ${argv[0]} (${color_text[0]})"
echo -e "Column 1 font color = ${argv[1]} (${color_text[1]})"
echo -e "Column 2 background = ${argv[2]} (${color_text[2]})"
echo -e "Column 2 font color = ${argv[3]} (${color_text[3]})"