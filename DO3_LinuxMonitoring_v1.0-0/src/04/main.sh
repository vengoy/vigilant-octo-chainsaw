#!/bin/bash
source config.conf

if [[ $# == 0 ]]
then
    bash print.sh $column1_background $column1_font_color $column2_background $column2_font_color
    bash color_system.sh
else
    echo "Error, only without arguments"
fi