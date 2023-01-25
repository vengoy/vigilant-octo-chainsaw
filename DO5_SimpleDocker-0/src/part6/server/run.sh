#!/bin/bash
gcc hello.c -lfcgi -o /home/hello
service nginx start
spawn-fcgi -p 8080 -n /home/hello