## Part 1. Установка ОС

* Устанавливаем Ubuntu 20.04 Server LTS без графического интерфейса
* Проверяем версию Ubuntu командой `cat /etc/issue`<br>
![version](screenshot/version.png)

## Part2. Создание пользователя

* Создаем нового пользователя командой `sudo adduser <имя пользователя>`<br>
<br>![user1](screenshot/user1.png)
<br>*Создание нового пользователя*<br>

* Даем новому пользователю права adm командой `sudo usermod -aG adm <имя пользователя>`<br>![usermod_adm](screenshot/usermod_adm.png)
  <br>*Присвоение прав вдминистратора*<br>
* Проверяем создание нового пользователя командой `cat /etc/passwd` <br>![etc_passwd](screenshot/etc_passwd.png)<br>*Проверка нового пользователя*<br>

## Part 3.  Настройка сети ОС

- Проверяем текущее название машины командой `hostname`<br>
 ![hostname](screenshot/hostname.png) 

- Изменяем название машины на user-1 использовав команду `sudo hostname user-1`<br>![hostnameUser-1](screenshot/hostnameUser-1.png)
* Далее меняем название машины в файлах hosts и hostname с помощью редактора nano командами `sudo nano /etc/hosts`<br> ![etchosts](screenshot/etchosts.png)
<br>*Редактируем файл hosts* и `sudo nano /etc/hostname`

* Вызываем перезагрузку системы для сохраниения изменений `sudo reboot`<br>![reboot](screenshot/reboot.png)<br>*Перезагружаем систему*

- Проверяем новое название машины командой `cat /etc/hostname`<br>![hostnameUser-1Update](screenshot/hostnameUser-1Update.png)

- Вызываем команду `timedatectl` для проверки текущего часового пояса<br>![timedatectl](screenshot/timedatectl.png)				
<br>*Проверка текущего часового пояса*<br>

- Задаем необходимый часовой пояс командой `sudo timedatectl set-timezone Europe/Moscow`<br>![timedatectlTimezone](screenshot/timedatectlTimezone.png)

* Проверяем изменения командой `timedatectl`<br>![timedatectlTimezoneMoscowRes](screenshot/timedatectlTimezoneMoscowRes.png)<br>*Проверяем изменения*<br>

* Выводим названия сетевых интерфейсов командой `ip addr` <br>![ipaddr](screenshot/ipaddr.png)<br>*Названия сетевых интерфейсов*<br>
- **Loopback** — совокупность методов, нужных для корректной работы маршрутизатора и передачи данных.<br>

- Сам интерфейс же является отображением логических процессов в маршрутизаторе. Также саму технологию используют и для других целей:<br>
  1) тестирование передачи данных от обслуживающего центра коммутации;<br>
  2) проверка сигнала на расстоянии;<br>
  3) обеспечение работы коммутационных кабелей и их проверка;<br>
  4) тест обратной петли, когда сигнал посылается и возвращается отправителю по всем коммуникационным каналам.<br>

- Использовав команду `ip r` узнаем ip-адрес устройства, от DHCP сервера 

  ![ip_r](screenshot/ip_r.png)<br> *ip-адрес устройства*

- **Dynamic Host Configuration Protocol (DHCP)** - это протокол управления сетью, используемый в сетях TCP/IP, в котором DHCP-сервер динамически присваивает каждому устройству IP-адрес и другие параметры сетевой конфигурации, чтобы они могли связываться с другими IP-сетями.<br>

* Выводим внешний и внутренний ip-адреса шлюза командами `curl 2ip.ru`<br>![ip_external](screenshot/ip_external.png)<br>*Внешний ip-адрес*
  и `ip route | grep default`<br>![ip_interior](screenshot/ip_interior.png)<br>Внутренний ip-адрес

* Задаем статичные настройки ip, gw, dns командой `sudo nano /etc/resolv.conf`<br>![resolv_conf](screenshot/resolv_conf.png)<br>*Редактирование настроек*<br>
- Перезагружаем виртуальную машину

- Проверяем, что статичные сетевые настройки (ip, gw, dns) соответствуют данным, командой  `ping -c 8 1.1.1.1 && ping -c 8 ya.ru`<br>![ping_ya&&11](screenshot/ping_ya&&11.png)

## Part 4. Обновление ОС

* Командой `sudo apt update` узнаём, сколько есть пакетов обновления<br>
* Обновляем системные пакеты до последней, на момент выполнения задания, версии командой `sudo apt full-upgrade`<br>
* После обновления системных пакетов, вводим команду обновления повторно, выводится сообщение, что обновления отсутствуют.<br>![update](screenshot/update.png)

## Part 5. Использование команды sudo

- sudo (англ. Substitute User and do, дословно «подменить пользователя и выполнить») — программа для системного администрирования UNIX-систем, позволяющая делегировать те или иные привилегированные ресурсы пользователям с ведением протокола работы.<br>
  Даем пользователю, созданному в Part 2, права на выполнение команды sudo `sudo usermod -a -G sudo <имя пользователя>`<br>![sudoUsermod](screenshot/sudoUsermod.png)<br>*Присвоение прав вдминистратора*<br>

- заходим на сервер под другим пользователем `su - <имя пользователя>`<br>

- Изменяем имя сервера на User-2, командой `sudo hostname User-2`. После ввода пароля проверяем изменения<br>![suUser1](screenshot/suUser1.png)<br>*Изменение имени сервера*

## Part 6. Установка и настройка службы времени

* Выводим текущее время команой `date`<br>![date](screenshot/date.png)<br>Текущее время

- Активируем NTP командой `sudo timedatectl set-ntp on`<br>

- Командой `timedatectl show` проверяем подключенную службу синхронизации

  ![timedateshowMSK](screenshot/timedateshowMSK.png)<br>NTPSynchronized активна

## Part 7. Установка и использование текстовых редакторов

- Устанввливаем тестовый редактор MCEDIT командой `sudo apt install mc`<br>

**Создаем и редактируем файл с сохранением изменений:**<br>**NANO:**

- Создаем файл командой `nano test_nano.txt` и записываем туда свой никнейм<br>

* Для выхода с сохранением используем команды: `ctrl+x`, `Y`, `Enter` либо `ctrl+o`, `Enter`, `ctrl+x`<br>![nano](screenshot/nano.png)<br>*NANO новый файл*

**VIM:**

* Создаем файл командой `vim test_vim.txt` и записываем туда свой никнейм (для прехода в режим вставки нажимаем `i`) <br>
* Для выхода с сохранением используем команды: `Esc`, `:wq`, `Enter`<br>![vim](screenshot/vim.png)<br>*VIM новый файл*

**MCEDIT:**

* Создаем файл командой `mcedit test_mcedit.txt` и записываем туда свой никнейм<br>
* Для выхода с сохранением используем команды: `fn+F2`, `Enter`, `fn+F10`<br>![mc](screenshot/mc.png)

**Редактируем файл без сохранения зменений:**<br>
**NANO:**

* Открываем файл командой `nano test_nano.txt` и меняем записаный никнейм на "21 School 21"<br>
* Для выхода без сохраненя используем команды: `ctrl+x`, `n`, `Enter`<br>![nano2](screenshot/nano2.png)<br>*NANO без сохранения*<br>

**VIM:**

* Открываем файл командой `vim test_vim.txt` и меняем записаный никнейм на "21 School 21" (для прехода в режим вставки нажимаем `i`) <br>
* Для выхода без сохранения используем команды: `Esc`, `:q!`, `Enter`<br>![vim2](screenshot/vim2.png)<br>VIM без сохранения

**MCEDIT:**

* Открываем файл командой `mcedit test_mcedit.txt` и меняем записаный никнейм на "21 School 21"<br>
* Для выхода без сохранения используем команды: `fn+F10`, `No`, `Enter`<br>![mc2](screenshot/mc2.png)<br>MCEDIT без сохранения

**Редактируем файл с поиском и заменой слова:**<br>
**NANO:**

* Открываем файл командой `nano test_nano.txt`<br>
* Для поиска в NANO используем комбинацию `ctrl+W`<br>![nano3](screenshot/nano3.png)<br>NANO поиск слова
* Для замены слова в NANO вводим `ctrl+\`, пишем слово для поиска, нажимаем `Enter`, пишем слово для замены, нажимаем `Enter`, выбираем `Y`<br>![nano4](screenshot/nano4.png)

**VIM:**

* Открываем файл командой `vim test_vim.txt`<br>
* Для поиска в VIM пишем команду `/<слово для поиска>`<br>![vim3](screenshot/vim3.png)<br>*VIM поиск слова*

- Для замены слова в VIM вводим используем команду `:%s/<заменяемое слово>/<новое слово>`<br>![vim4](screenshot/vim4.png)

**MCEDIT:**

* Открываем файл командой `mcedit test_mcedit.txt`<br>
* Для поиска в MCEDIT используем комбинацию `fn+F7` вводим нужное слово или строку и нажимаем   `Enter`<br>![mc3](screenshot/mc3.png)

- Для замены слова в MCEDIT используем комбинацию `fn+F4` в первом поле пишем заменяемое слово, во втором поле пишем новое слово, нажимаем `Enter` и выбираем `Заменить`<br>![mc4](screenshot/mc4.png)

## Part 8. Установка и базовая настройка сервиса SSHD

* Командой `sudo apt install openssh-server` устанавливаем службу SSHd<br>
* Подключаем автостарт службы `sudo update-rc.d ssh defaults`<br>
* Для настройки порта открываем текстовый редактор `sudo nano /etc/ssh/sshd_config` и добавляем строку "Port 2022"<br>![sshd_config](screenshot/sshd_config.png)
  

- Перезапускаем сервер SSH для применения изменений `/etc/init.d/ssh restart`<br>

- Используя команду `ps -axfv | grep sshd` проверяем наличие процесса SSHd<br>![ps_sshd](screenshot/ps_sshd.png)
- Команда `ps` выводит список текущих процессов на вашем сервере. Используется обычно в сочетании с командой `grep`<br>

* Флаги:<br>
  -a: Выбирает все процессы, кроме лидеров сеансов и процессов, не связанных с терминалом.<br>
  -x: Заставляет `ps` отображать список всех процессов, которыми вы владеете (тот же EUID, что и у `ps`), или перечислять все процессы при использовании вместе с опцией a<br>
  -f: Выводит полноформатный список<br>
  -v: Выводит информацию о версии<br>

* Комндой `sudo apt install net-tools` устанавливаем "net-tools" после чего выполняем команду `netstat -tan`<br>![netstat](screenshot/netstat.png)

* Опция **-a** показывает состояние всех сокетов; **-n** показывает ip адрес, а не сетевое имя; **-t** показывает только tcp соединения.<br>
* Значения столбцов:<br>
  1) Proto - протокол, используемый сокетом;<br>
  2) Recv-Q - количество байтов, не скопированных пользовательской программой, подключенной к этому сокету;<br>
  3) Local Address - локальный адрес (имя локального хоста) и номер порта сокета;<br>
  4) Foreign Address - удаленный адрес (имя удаленного хоста) и номер порта сокета;<br>
  5) State - состояние сокета;<br>
  6) 0.0.0.0 в этом контексте означает "все IP-адреса на локальной машине".<br>

## Part 9. Установка и использование утилит **top**, **htop**

**top:**<br>

* Запускаем утилиту `top` одноименной командой и видим необходимую информацию![top](screenshot/top.png)<br>

* Для того, чтобы узнать pid процесса, занимающего больше всего памяти выполним запуск "top" с сортировкой по проценту занятой памяти `top -b -o +%MEM | head -n 22` необходимый процесс будет первым в списке (в данном случае PID процесса - 632)<br>![topHead](screenshot/topHead.png)<br>*pid процесса занимающего больше всего памяти*<br>

- По аналогии с предыдущим пунктом узнаем pid процесса, занимающего больше всего процессорного времени `top -b -o +TIME | head -n 22` (в данном случае PID - 1)<br>![top_time](screenshot/top_time.png)

**htop:**<br>

* Запускаем утилиту командой `htop`, для изменения типа сортировку используем `F6`<br>![htopByPid](screenshot/htopByPid.png)<br>*PID*

* ![htop](screenshot/htop.png)<br>*PERCENT_CPU*
* ![htopByMem](screenshot/htopByMem.png)<br>*PERCENT_MEM*

* ![htopByTime](screenshot/htopByTime.png)<br>*TIME*
* Для фильтрации процессов по названию используем комбинацию клавиш `fn+F4` пишем необходимое название в данном случае  "sshd"<br>![htopByName](screenshot/htopByName.png)<br>*SSHd*
* Для поиска процесса `syslog` используем функцию поиска процессов `fn+F3`<br>![htop_syslog](screenshot/htop_syslog.png)<br>*syslog*

## Part 10. Использование утилиты **fdisk**

- Запускаем утилиту командой `sudo fdisk -l`<br>![fdisk](screenshot/fdisk.png)

* *Информация о жестком диске*<br>
    * Название жесткого диска: VBOX HARDDISK<br>
    * Размер: 10 GiB<br>
    * Количество секторов: 20971520<br>
    * Размер swap: 1.70GiB

## Part 11. Использование утилиты **df**

- Запускаем команду `df` либо `df /`, для сортировки по корневому разделу<br>![df](screenshot/df.png)

- *df корневой раздел*<br>
    * Размер раздела: 9299276<br>
    * Размер занятого пространства: 4149700<br>
    * Размер свободного пространства: 4655600<br>
    * Процент использования: 48%<br>
    * Единица измерения в выводе: Кб<br>

* Запускаем команду `df -Th` либо `df -Th /`, для сортировки по корневому разделу<br>![df_Th](screenshot/df_Th.png)<br>*df -Th корневой раздел*<br>

  * Размер раздела: 8.9G<br>
  * Размер занятого пространства: 4G<br>
  * Размер свободного пространства: 4.5G<br>
  * Процент использования: 48%<br>
  * Тип файловой системы для раздела: ext4<br>

## Part 12. Использование утилиты **du**

* Запускаем команду `du`<br>![du](screenshot/du.png)<br>*Вывод команды du*

* Выводим размер папок в байтах `/home`, `/var`, `/var/log` с помощью команды `sudo du -s -h -b /home && sudo du -s -h -b /var && sudo du -s -h -b /var/log`<br>![du_dir](screenshot/du_dir.png)<br>*Размер папок в байтах*

- Выводим размер всего содержимого в `/var/log` с помощью команды `sudo du -a -h /var/log`<br>![du_var_log](screenshot/du_var_log.png)

  

## Part 13. Установка и использование утилиты **ncdu**

* Устанавливаем утилиту **ncdu** командой `sudo apt install ncdu`<br>
* Выводим размер необходимых папок используя команду `ncdu`:<br>![ncdu_home](screenshot/ncdu_home.png)<br><br>*ncdu /home*

* ![ncdu_var](screenshot/ncdu_var.png)<br>ncdu /var

* ![ncdu_var_log](screenshot/ncdu_var_log.png)<br>*ncdu /var/log*

## Part 14. Работа с системными журналами

* Открываем для просмотра системные журналы:<br>
* ![var_log_dmesg](screenshot/var_log_dmesg.png)<br>*cat /var/log/dmesg*

* ![var_log_syslog](screenshot/var_log_syslog.png)<br>*cat /var/log/syslog*

* ![var_log_auth](screenshot/var_log_auth.png)<br>*cat /var/log/auth.log*

* Для того чтобы узнать время последней успешной авторизации используем команду `last`<br>![last](screenshot/last.png)<br>*Время последней успешной авторизации*

* перезапускаем службу SSHd и проверяем и ищем в логах сообщение о рестарте службы командами `sudo systemctl restart ssh` и `cat /var/log/syslog`<br>![log_of_sshd](screenshot/log_of_sshd.png)<br>*Перезапуск SSHd в логах*

## Part 15. Использование планировщика заданий **CRON**

* Настраиваем cron для работы в фоновом режиме `sudo systemctl enable cron`<br>
* Для того, чтобы запланировать задачу используем команду `crontab -e`, затем выбираем один из предложенных текстовых редакторов<br>
* В открывшемся файле дописываем необходимую задачу (в нашем случае `"*/2 * * * * uptime"`), сохрняем и закрываем редактор, в терминале отобразится соощение об успешном добавлении задачи<br>![cron](screenshot/cron.png)

* Проверяем список текущих задач командой `crontab -l`<br>![crontab](screenshot/crontab.png)<br>*список текущих задач*

* Проверяем выполение задач в логах командой `grep CRON /var/log/syslog`<br>![cron_var_log](screenshot/cron_var_log.png)<br>*Задача uptime в логах*

* Для удаления всех задач из планировщика используем команду `crontab -r`<br>![crontab_r_l](screenshot/crontab_r_l.png)<br>*Задачи отсутсвуют*
