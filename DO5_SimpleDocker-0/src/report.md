### Part 1. Готовый докер
- Взять официальный докер образ с nginx и выкачать его при помощи docker pull nginx Image
- Проверил наличие докер образа через docker images
- Запустил докер образ через ``docker run -d [image_id|repository]``
- Проверил, что образ запустился через docker ps
![](./part1/part1_docker_pull_nginx.png)
- Просмотр информации о контейнере при помощи команды docker inspect container_id<br>![](./part1/part1_docker_inspect.png)
- размер контейнера <br>![](./part1/part1_docker_inspect_Size.png)<br>
- список замапленных портов <br>![](./part1/part1_docker_inspect_ports.png)<br>
- ip контейнера<br>![](./part1/part1_docker_inspect_ip.png)<br>
- Остановить докер образ через docker stop [container_id|container_name]<br> Проверить, что образ остановился через docker ps
![](./part1/part1_docker_stop.png)
- Запустить докер с портами 80 и 443 на локальную машину через команду run<br>
![](./part1/part1_docker_nginx_ports.png)<br>
- Перезапуск докера и проверка, что он запустился![](./part1/part1_docker_restart.png)<br>
---
### Part 2. Операции с контейнером
- Прочитать конфигурационный файл nginx.conf внутри докер контейнера через команду exec<br>![](./part2/part2_docker_exec.png)
- Создать на локальной машине файл nginx.conf
<br>![](./part2/part2_NginxConf.png)
- Скопировать созданный файл nginx.conf внутрь докер образа через команду docker cp и проверить, что по адресу localhost:80/status отдается страничка со статусом сервера nginx<br>![](./part2/part2_NginxConfstatus.png)
- Экспортировать контейнер в файл container.tar через команду export.<br>![](./part2/part2_docker_export.png)
- Удалить образ через docker rmi [image_id|repository], не удаляя перед этим контейнеры<br>![](./part2/part2_docker_rmi.png)
- Удалить остановленный контейнер<br>![](./part2/part2_docker_rm.png)
- Импорт контейнера обратно. Запуск импортированного контейнера.<br>![](./part2/part2_docker_import.png) 
- Проверка работоспособности контейнера.<br>![](./part2/part2_docker_import_image_and_run.png)
---
### Part 3. Мини веб-сервер
- Мини сервер на C и FastCgi, который будет возвращать Hello World!<br>![](./part3/part3_hello_c.png)
- Создание nginx.conf<br>![](./part3/part3_nginx_conf.png)
- Выкачка докера nginx. Проверка, что загрузка прошла успешно.Запуск образа и проверка, что он запустился <br>![](./part3/part3_nginx_start_docker.png)
- Копирование nginx.conf и hello.c в докер-контейнер<br>![](./part3/part3_docker_cp_files.png)
- Обновление контейнера. Установка gcc, spawn-dcgi, libfcgi-dev<br>![](./part3/part3_docker_update.png)
- Компиляция и запуск сервера <br>![](./part3/part3_docker_server_start.png)
- Перезагрузка nginx и проверка страницы в браузере<br>![](./part3/part3_nginx_reload_and_check.png)
---
### Part 4. Свой докер
- Создание докер образа<br>![](./part4/part4_cat_src.png)
- Сбор написанного образа. Маппинг 81 порта на 80.<br>![](./part4/part4_build&run.png)
- Проверка на корректность<br>![](./part4/part4_check.png)
---
### Part 5. Dockle
- Сканирование образа<br>![](./part5/part5_dockle_res.png)
- Проверка на отсутствие ошибок и предупреждений после исправления образа<br>![](./part5/part5_dockle_fix.png)
---
### Part 6. Базовый Docker Compose
- Файл docker-compose.yml<br>![](./part6/part6_docker-compose.png)
- Создадим Dockerfile для proxy.<br>![](./part6/part6_docker_proxy.png)
- Собираем и запускаем проект<br>![](./part6/part6_build_and_check.png)

