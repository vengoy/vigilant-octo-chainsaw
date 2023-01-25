#!/usr/bin/expect -f
#copy to remote-pc
spawn scp -o "StrictHostKeyChecking no" cat/s21_cat grep/s21_grep dottiesu@192.168.56.200:/usr/local/bin
expect -exact "\rdottiesu@192.168.56.200's password: "
send -- "name_pls\r"
expect eof
