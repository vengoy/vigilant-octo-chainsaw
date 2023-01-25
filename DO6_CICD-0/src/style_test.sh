#!/bin/bash
echo "clang-format -n cat/s21_cat.c"
clang-format -n cat/s21_cat.c 2>trest.txt

if [[ -s trest.txt ]]; then
    echo "code style bugs in s21_cat.c"
    cat trest.txt
    echo "clang-format -n grep/s21_grep.c"
    clang-format -n grep/s21_grep.c 2>trest.txt
    if [[ -s trest.txt ]]; then
        echo "some bugs in s21_grep.c"
        cat trest.txt
        rm trest.txt
    fi
    exit 1
fi

echo "clang-format -n grep/s21_grep.c"
clang-format -n grep/s21_grep.c 2>trest.txt
if [[ -s trest.txt ]]; then
    echo "code style bugs in s21_grep.c"
    cat trest.txt
    rm trest.txt
    exit 1
fi
rm trest.txt
