# Отчёт по лабораторной работе №2 по курсу “Фундаментальная информатика”

<b>Студент группы:</b> <ins>М80-108Б-22 Былькова Кристина Алексеевна, № по списку 2</ins> 

<b>Контакты e-mail:</b> <ins>kristina.bilckova@yandex.ru</ins>

<b>Работа выполнена:</b> «24» <ins>сентября</ins> <ins>2022</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>5 (отлично)</ins>

<b>Отчет сдан</b> «24» <ins>сентября</ins> <ins>2022</ins> г., <b>итоговая оценка</b> <ins>5 (отлично)</ins>

<b>Подпись преподавателя:</b> ________________

## 1. Тема
Операционная среда OC UNIX
## 2. Цель работы
Изучение и освоение программного обеспечения ОС UNIX и приобретение навыков, необходимых для выполнения курсовых и лабораторных работ в среде UNIX.
## 3. Задание (вариант № —)
Изучение команд и утилит bash.
## 4. Оборудование:
<b>Процессор:</b> 1,6 GHz 2-ядерный Intel Core i5-8210Y<br/>
<b>ОП:</b> 8 ГБ 2133 MHz LPDDR3<br/>
<b>SSD:</b> 256 ГБ<br/>
<b>Адрес:</b> 95.31.164.228<br/>
<b>Монитор:</b> 13,3-дюймовый (2560 х 1600)<br/>
<b>Графика:</b> Intel UHD Graphics 617 1536 МБ<br/>
## 5. Программное обеспечение:
<b>Операционная система семейства:</b> VirtualBox 6.1.38 - Ubuntu 22.04.01 LTS<br/>
<b>Интерпретатор команд:</b> bash версия 4.4.19<br/>
<b>Система программирования:</b> не использовалась версия —<br/>
<b>Редактор текстов:</b> emacs версия 25.2.2<br/>
<b>Утилиты операционной системы:</b> cd, pwd, ls, cp, mv, mkdir, rmdir, cat, man, ps, rm<br/>
<b>Прикладные системы и программы:</b> gnuplot<br/>
<b>Местонахождение и имена файлов программ и данных на домашнем компьютере:</b> /home/kristina<br/>
## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)
Изучить основы программного обеспечения ОС UNIX
Ввод команд:
1. ```ls -l/-A/-lAF``` – ознакомление с содержимым директории
2. ```whoami``` – определение имени пользователя
3. ```hostname``` – определение терминала, котором ведётся работа
4. ```date``` – определение даты
5. ```tty``` – определение номера группы имени пользователя
6. ```uname -a``` – определение сетевого имени машины
7. ```finger kristina``` – отображение полного имени и другой информации о пользователе
8. ```pwd``` – отображение полного пути к текущей директории
9. ```sudo ruptime``` – узнать, какие узлы сети в настоящий момент доступны, а какие нет
10. ```sudo rwho``` – узнать, какие пользователи работают на всех доступных UNIX-машинах
11. ```uptime``` – показывает текущее время, время работы после загрузки, количество  текущих пользователей и  нагрузку за последние 1, 5, 15 минут
12. ```man``` – получение оперативной документации по командам UNIX
13. ```cd``` – переход в другую директорию
14. ```ps``` - процессор
15. ```emacs``` – текстовый редактор
16. ```cp``` – копировать
17. ```cat``` – создание нового файла с возможностью записи/копировать
18. ```touch``` – создание пустого файла, если его нет. Если файл есть, то команда установит дату обращения в текущий момент времени 
19. ```rm``` – удаление
20. ```mv``` – перемещение
21. ```mkdir``` – создание директории
22. ```rmdir``` – удаление директории
23. ```gnuplot``` – утилита графики для построения двух- и трехмерных графиков
24. ```chmod +x ./myscript``` – делает скрипт исполняемым
25. ```./myscript``` – запуск скрипта
26. ```exit``` – выход
27. ```vim``` – текстовый редактор

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
- Изучить литературу по OC UNIX
- Просмотреть демонстрационный материал в лабораторной аудитории
- Приобрести основные навыки работы в OC UNIX
- Освоить навигацию в иерархической файловой системе OC UNIX
- Научиться манипулировать с файлами 
- Ознакомиться с утилитой графики 
- Научиться писать и запускать скрипты
- Запротоколировать сеанс

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________
## 8. Распечатка протокола 
```
kristina@kristina-VirtualBox:~$ ls
 snap    Документы   Изображения   Общедоступные   Шаблоны
 Видео   Загрузки    Музыка       'Рабочий стол'
kristina@kristina-VirtualBox:~$ ls -1
snap
Видео
Документы
Загрузки
Изображения
Музыка
Общедоступные
'Рабочий стол'
Шаблоны
kristina@kristina-VirtualBox:~$ ls -A
 .bash_history   .emacs.d           snap                        Изображения
 .bash_logout    .gnuplot_history   .sudo_as_admin_successful   Музыка
 .bashrc         .lesshst           Видео                       Общедоступные
 .cache          .local             Документы                  'Рабочий стол'
 .config         .profile           Загрузки                    Шаблоны
kristina@kristina-VirtualBox:~$ ls -lAF
итого 76
-rw-------  1 kristina kristina  207 сен 14 15:48  .bash_history
-rw-r--r--  1 kristina kristina  220 сен 14 00:16  .bash_logout
-rw-r--r--  1 kristina kristina 3771 сен 14 00:16  .bashrc
drwx------ 10 kristina kristina 4096 сен 14 00:23  .cache/
drwx------ 11 kristina kristina 4096 сен 16 13:29  .config/
drwx------  2 kristina kristina 4096 сен 14 00:28  .emacs.d/
-rw-------  1 kristina kristina   40 сен 14 00:27  .gnuplot_history
-rw-------  1 kristina kristina   20 сен 14 17:16  .lesshst
drwx------  3 kristina kristina 4096 сен 14 00:21  .local/
-rw-r--r--  1 kristina kristina  807 сен 14 00:16  .profile
drwx------  4 kristina kristina 4096 сен 14 17:30  snap/
-rw-r--r--  1 kristina kristina    0 сен 14 00:27  .sudo_as_admin_successful
drwxr-xr-x  2 kristina kristina 4096 сен 14 00:21  Видео/
drwxr-xr-x  2 kristina kristina 4096 сен 14 00:21  Документы/
drwxr-xr-x  2 kristina kristina 4096 сен 14 00:21  Загрузки/
drwxr-xr-x  2 kristina kristina 4096 сен 14 00:21  Изображения/
drwxr-xr-x  2 kristina kristina 4096 сен 14 00:21  Музыка/
drwxr-xr-x  2 kristina kristina 4096 сен 14 00:21  Общедоступные/
drwxr-xr-x  2 kristina kristina 4096 сен 14 00:21 'Рабочий стол'/
drwxr-xr-x  2 kristina kristina 4096 сен 14 00:21  Шаблоны/
kristina@kristina-VirtualBox:~$ whoami
kristina
kristina@kristina-VirtualBox:~$ hostname
kristina-VirtualBox
kristina@kristina-VirtualBox:~$ date
Ср 21 сен 2022 18:04:00 MSK
kristina@kristina-VirtualBox:~$ tty
/dev/pts/0
kristina@kristina-VirtualBox:~$ uname -a
Linux kristina-VirtualBox 5.15.0-47-generic #51-Ubuntu SMP Thu Aug 11 07:51:15 UTC 2022 x86_64 x86_64 x86_64 GNU/Linux
kristina@kristina-VirtualBox:~$ finger kristina
Login: kristina       			Name: kristina
Directory: /home/kristina           	Shell: /bin/bash
On since Thu Sep 22 13:38 (MSK) on tty2 from tty2
   1 minute 40 seconds idle
No mail.
No Plan.
kristina@kristina-VirtualBox:~$ pwd
/home/kristina
kristina@kristina-VirtualBox:~$ sudo ruptime
[sudo] пароль для kristina: 
kristina-Vir  up       0:01,     0 users,  load 0.80, 0.16, 0.05
kristina@kristina-VirtualBox:~$ sudo rwho
kristina@kristina-VirtualBox:~$ uptime
 18:13:06 up 53 min,  1 user,  load average: 0,47, 0,32, 0,26
kristina@kristina-VirtualBox:~$ man ls
kristina@kristina-VirtualBox:~$ ps
    PID TTY          TIME CMD
   1625 pts/0    00:00:00 bash
   3029 pts/0    00:00:00 ps
kristina@kristina-VirtualBox:~$ cd /
kristina@kristina-VirtualBox:/$ ls
bin    dev   lib    libx32      mnt   root  snap      sys  var
boot   etc   lib32  lost+found  opt   run   srv       tmp
cdrom  home  lib64  media       proc  sbin  swapfile  usr
kristina@kristina-VirtualBox:/$ cd /bin
kristina@kristina-VirtualBox:/bin$ cd ..
kristina@kristina-VirtualBox:~$ cat > f1.txt
test file
kristina@kristina-VirtualBox:~$ ls
 f1.txt   Видео       Загрузки      Музыка         'Рабочий стол'
 snap     Документы   Изображения   Общедоступные   Шаблоны
kristina@kristina-VirtualBox:~$ cat f1.txt
test file
kristina@kristina-VirtualBox:~$ emacs f1.txt
kristina@kristina-VirtualBox:~$ cp f1.txt f2.txt
kristina@kristina-VirtualBox:~$ ls
 f1.txt   snap    Документы   Изображения   Общедоступные   Шаблоны
 f2.txt   Видео   Загрузки    Музыка       'Рабочий стол'
kristina@kristina-VirtualBox:~$ cat f2.txt
test file
kristina@kristina-VirtualBox:~$ cat f1.txt f2.txt > f3.txt
kristina@kristina-VirtualBox:~$ ls
 f1.txt   f3.txt   Видео       Загрузки      Музыка         'Рабочий стол'
 f2.txt   snap     Документы   Изображения   Общедоступные   Шаблоны
kristina@kristina-VirtualBox:~$ cat f3.txt
test file
test file
kristina@kristina-VirtualBox:~$ rm f2.txt
kristina@kristina-VirtualBox:~$ rm f3.txt
kristina@kristina-VirtualBox:~$ ls
 f1.txt   Видео       Загрузки      Музыка         'Рабочий стол'
 snap     Документы   Изображения   Общедоступные   Шаблоны
kristina@kristina-VirtualBox:~$ mkdir course
kristina@kristina-VirtualBox:~$ ls -1
course
f1.txt
snap
Видео
Документы
Загрузки
Изображения
Музыка
Общедоступные
'Рабочий стол'
Шаблоны
kristina@kristina-VirtualBox:~$ mv f1.txt course
kristina@kristina-VirtualBox:~$ ls -1
course
snap
Видео
Документы
Загрузки
Изображения
Музыка
Общедоступные
'Рабочий стол'
Шаблоны
kristina@kristina-VirtualBox:~$ cd course
kristina@kristina-VirtualBox:~/course$ ls -1
f1.txt
kristina@kristina-VirtualBox:~/course$ cd ..
kristina@kristina-VirtualBox:~$ ls -1
course
snap
Видео
Документы
Загрузки
Изображения
Музыка
Общедоступные
'Рабочий стол'
Шаблоны
kristina@kristina-VirtualBox:~$ rmdir course
rmdir: не удалось удалить 'course': Каталог не пуст
kristina@kristina-VirtualBox:~$ cd course
kristina@kristina-VirtualBox:~/course$ rm f1.txt
kristina@kristina-VirtualBox:~/course$ cd ..
kristina@kristina-VirtualBox:~$ rmdir course
kristina@kristina-VirtualBox:~$ ls -1
snap
Видео
Документы
Загрузки
Изображения
Музыка
Общедоступные
'Рабочий стол'
Шаблоны
kristina@kristina-VirtualBox:~$ gnuplot

	G N U P L O T
	Version 5.4 patchlevel 2    last modified 2021-06-01 

	Copyright (C) 1986-1993, 1998, 2004, 2007-2021
	Thomas Williams, Colin Kelley and many others

	gnuplot home:     http://www.gnuplot.info
	faq, bugs, etc:   type "help FAQ"
	immediate help:   type "help"  (plot window: hit 'h')

Terminal type is now 'qt'
gnuplot> plot sin(x)*cos(x)
 
Warning: Ignoring XDG_SESSION_TYPE=wayland on Gnome. Use QT_QPA_PLATFORM=wayland to run on Wayland anyway.
gnuplot> set parametric

	dummy variable is t for curves, u/v for surfaces
gnuplot> set trange [0 to 2*pi]
gnuplot> set xrange [-1 to 1]
gnuplot> set yrange [-1 to 1]
gnuplot> plot sin(t),cos(t)
 
gnuplot> set zrange [-1 to 1]
gnuplot> set urange [0 to 2*pi]
gnuplot> set vrange [0 to 2*pi]
gnuplot> unset hidden3d
gnuplot> splot sin(u)*sin(v),sin(u)*cos(v),cos(u)
 
gnuplot> unset parametric
gnuplot> set term dumb

Terminal type is now 'dumb'
Options are 'feed  size 79, 24 aspect 2, 1 mono'
gnuplot> plot sin(x)*cos(x)
                                                                                
gnuplot> exit
kristina@kristina-VirtualBox:~$ touch myscript
kristina@kristina-VirtualBox:~$ chmod +x ./myscript
kristina@kristina-VirtualBox:~$ ./myscript
kristina
kristina@kristina-VirtualBox:~$ ls
 f1.txt     snap    Документы   Изображения   Общедоступные   Шаблоны
 myscript   Видео   Загрузки    Музыка       'Рабочий стол'
kristina@kristina-VirtualBox:~$ cat f1.txt
Hello, world!
kristina@kristina-VirtualBox:~$ rm f1.txt
kristina@kristina-VirtualBox:~$ rm myscript
kristina@kristina-VirtualBox:~$ ls
 snap    Документы   Изображения   Общедоступные   Шаблоны
 Видео   Загрузки    Музыка       'Рабочий стол'
kristina@kristina-VirtualBox:~$ exit
```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 24.09.22 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
```
kristina@kristina-VirtualBox:~$ ls -lAF
итого 100
-rw-------  1 kristina kristina 3615 сен 24 14:12  .bash_history
-rw-r--r--  1 kristina kristina  220 сен 14 00:16  .bash_logout
-rw-r--r--  1 kristina kristina 3771 сен 14 00:16  .bashrc
drwx------ 12 kristina kristina 4096 сен 24 09:30  .cache/
drwx------ 14 kristina kristina 4096 сен 21 00:21  .config/
drwx------  3 kristina kristina 4096 сен 21 00:33  .emacs.d/
drwx------  2 kristina kristina 4096 сен 21 17:56  .gnupg/
-rw-------  1 kristina kristina  668 сен 21 00:21  .gnuplot_history
-rw-------  1 kristina kristina   20 сен 24 13:32  .lesshst
drwx------  3 kristina kristina 4096 сен 14 00:21  .local/
-rwxrwxr-x  1 kristina kristina   49 сен 23 22:39  myscript*
-rw-rw-r--  1 kristina kristina    0 сен 23 22:37  myscript~
-rw-r--r--  1 kristina kristina  807 сен 14 00:16  .profile
drwx------  4 kristina kristina 4096 сен 14 17:30  snap/
drwx------  2 kristina kristina 4096 сен 21 17:56  .ssh/
-rw-r--r--  1 kristina kristina    0 сен 14 00:27  .sudo_as_admin_successful
-rw-rw-r--  1 kristina kristina   24 сен 24 12:57  test1.txt
-rw-rw-r--  1 kristina kristina   18 сен 24 12:48  test1.txt~
-rw-------  1 kristina kristina 1659 сен 24 12:57  .viminfo
drwxr-xr-x  2 kristina kristina 4096 сен 14 00:21  Видео/
drwxr-xr-x  2 kristina kristina 4096 сен 14 00:21  Документы/
drwxr-xr-x  2 kristina kristina 4096 сен 24 09:30  Загрузки/
d------rwx  2 kristina kristina 4096 сен 14 00:21  Изображения/
drwxr-xr-x  2 kristina kristina 4096 сен 14 00:21  Музыка/
drwxr-xr-x  2 kristina kristina 4096 сен 14 00:21  Общедоступные/
drwxr-xr-x  4 kristina kristina 4096 сен 24 18:52 'Рабочий стол'/
drwxr-xr-x  2 kristina kristina 4096 сен 14 00:21  Шаблоны/
kristina@kristina-VirtualBox:~$ chmod ugo+rwx Изображения/
kristina@kristina-VirtualBox:~$ ls -lAF
итого 100
-rw-------  1 kristina kristina 3615 сен 24 14:12  .bash_history
-rw-r--r--  1 kristina kristina  220 сен 14 00:16  .bash_logout
-rw-r--r--  1 kristina kristina 3771 сен 14 00:16  .bashrc
drwx------ 12 kristina kristina 4096 сен 24 09:30  .cache/
drwx------ 14 kristina kristina 4096 сен 21 00:21  .config/
drwx------  3 kristina kristina 4096 сен 21 00:33  .emacs.d/
drwx------  2 kristina kristina 4096 сен 21 17:56  .gnupg/
-rw-------  1 kristina kristina  668 сен 21 00:21  .gnuplot_history
-rw-------  1 kristina kristina   20 сен 24 13:32  .lesshst
drwx------  3 kristina kristina 4096 сен 14 00:21  .local/
-rwxrwxr-x  1 kristina kristina   49 сен 23 22:39  myscript*
-rw-rw-r--  1 kristina kristina    0 сен 23 22:37  myscript~
-rw-r--r--  1 kristina kristina  807 сен 14 00:16  .profile
drwx------  4 kristina kristina 4096 сен 14 17:30  snap/
drwx------  2 kristina kristina 4096 сен 21 17:56  .ssh/
-rw-r--r--  1 kristina kristina    0 сен 14 00:27  .sudo_as_admin_successful
-rw-rw-r--  1 kristina kristina   24 сен 24 12:57  test1.txt
-rw-rw-r--  1 kristina kristina   18 сен 24 12:48  test1.txt~
-rw-------  1 kristina kristina 1659 сен 24 12:57  .viminfo
drwxr-xr-x  2 kristina kristina 4096 сен 14 00:21  Видео/
drwxr-xr-x  2 kristina kristina 4096 сен 14 00:21  Документы/
drwxr-xr-x  2 kristina kristina 4096 сен 24 09:30  Загрузки/
drwxrwxrwx  2 kristina kristina 4096 сен 14 00:21  Изображения/
drwxr-xr-x  2 kristina kristina 4096 сен 14 00:21  Музыка/
drwxr-xr-x  2 kristina kristina 4096 сен 14 00:21  Общедоступные/
drwxr-xr-x  4 kristina kristina 4096 сен 24 18:52 'Рабочий стол'/
drwxr-xr-x  2 kristina kristina 4096 сен 14 00:21  Шаблоны/
kristina@kristina-VirtualBox:~$ ps
    PID TTY          TIME CMD
   1631 pts/0    00:00:00 bash
   1797 pts/0    00:00:00 ps
kristina@kristina-VirtualBox:~$ gnuplot
	G N U P L O T
	Version 5.4 patchlevel 2    last modified 2021-06-01 

	Copyright (C) 1986-1993, 1998, 2004, 2007-2021
	Thomas Williams, Colin Kelley and many others

	gnuplot home:     http://www.gnuplot.info
	faq, bugs, etc:   type "help FAQ"
	immediate help:   type "help"  (plot window: hit 'h')

Terminal type is now 'qt'
gnuplot>
kristina@kristina-VirtualBox:~$ ps -A
    PID TTY          TIME CMD
      1 ?        00:00:01 systemd
      2 ?        00:00:00 kthreadd
      3 ?        00:00:00 rcu_gp
      4 ?        00:00:00 rcu_par_gp
      5 ?        00:00:00 netns
      6 ?        00:00:00 kworker/0:0-rcu_gp
      7 ?        00:00:00 kworker/0:0H-events_highpri
      8 ?        00:00:00 kworker/u4:0-events_unbound
      9 ?        00:00:00 kworker/0:1H-events_highpri
     10 ?        00:00:00 mm_percpu_wq
     11 ?        00:00:00 rcu_tasks_rude_
     12 ?        00:00:00 rcu_tasks_trace
     13 ?        00:00:00 ksoftirqd/0
     14 ?        00:00:00 rcu_sched
     15 ?        00:00:00 migration/0
     16 ?        00:00:00 idle_inject/0
     17 ?        00:00:00 kworker/0:1-cgroup_destroy
     18 ?        00:00:00 cpuhp/0
     19 ?        00:00:00 cpuhp/1
     20 ?        00:00:00 idle_inject/1
     21 ?        00:00:00 migration/1
     22 ?        00:00:00 ksoftirqd/1
     23 ?        00:00:00 kworker/1:0-cgroup_destroy
     24 ?        00:00:00 kworker/1:0H-events_highpri
     25 ?        00:00:00 kdevtmpfs
     26 ?        00:00:00 inet_frag_wq
     27 ?        00:00:00 kauditd
     28 ?        00:00:00 khungtaskd
     29 ?        00:00:00 oom_reaper
     30 ?        00:00:00 writeback
     31 ?        00:00:00 kcompactd0
     32 ?        00:00:00 ksmd
     33 ?        00:00:00 khugepaged
     38 ?        00:00:00 kworker/1:1-events
     80 ?        00:00:00 kintegrityd
     81 ?        00:00:00 kblockd
     82 ?        00:00:00 blkcg_punt_bio
     83 ?        00:00:00 tpm_dev_wq
     84 ?        00:00:00 ata_sff
     85 ?        00:00:00 md
     86 ?        00:00:00 edac-poller
     87 ?        00:00:00 devfreq_wq
     88 ?        00:00:00 watchdogd
     89 ?        00:00:00 kworker/u4:1-flush-8:0
     91 ?        00:00:00 kswapd0
     92 ?        00:00:00 ecryptfs-kthrea
     94 ?        00:00:00 kthrotld
     95 ?        00:00:00 acpi_thermal_pm
     96 ?        00:00:00 kworker/u4:2-loop12
     97 ?        00:00:00 scsi_eh_0
     98 ?        00:00:00 scsi_tmf_0
     99 ?        00:00:00 kworker/u4:3-events_power_efficient
    100 ?        00:00:00 scsi_eh_1
    101 ?        00:00:00 scsi_tmf_1
    102 ?        00:00:00 vfio-irqfd-clea
    103 ?        00:00:00 kworker/u4:4-events_unbound
    104 ?        00:00:00 kworker/1:1H-events_highpri
    105 ?        00:00:00 mld
    106 ?        00:00:00 ipv6_addrconf
    108 ?        00:00:00 kworker/u4:5-events_unbound
    109 ?        00:00:00 kworker/1:2-events
    117 ?        00:00:00 kstrp
    120 ?        00:00:00 zswap-shrink
    121 ?        00:00:00 kworker/u5:0
    126 ?        00:00:00 charger_manager
    170 ?        00:00:00 kworker/1:3-events
    171 ?        00:00:00 kworker/0:2-events
    172 ?        00:00:00 scsi_eh_2
    173 ?        00:00:00 scsi_tmf_2
    198 ?        00:00:00 jbd2/sda3-8
    199 ?        00:00:00 ext4-rsv-conver
    239 ?        00:00:00 systemd-journal
    261 ?        00:00:00 kworker/0:3-events
    272 ?        00:00:00 ipmi-msghandler
    282 ?        00:00:00 ttm_swap
    283 ?        00:00:00 irq/18-vmwgfx
    285 ?        00:00:00 card0-crtc0
    287 ?        00:00:00 card0-crtc1
    288 ?        00:00:00 card0-crtc2
    289 ?        00:00:00 card0-crtc3
    290 ?        00:00:00 card0-crtc4
    291 ?        00:00:00 card0-crtc5
    292 ?        00:00:00 card0-crtc6
    293 ?        00:00:00 card0-crtc7
    299 ?        00:00:00 systemd-udevd
    356 ?        00:00:00 cryptd
    421 ?        00:00:00 systemd-oomd
    422 ?        00:00:00 systemd-resolve
    423 ?        00:00:00 systemd-timesyn
    588 ?        00:00:00 accounts-daemon
    594 ?        00:00:00 acpid
    598 ?        00:00:00 avahi-daemon
    599 ?        00:00:00 cron
    600 ?        00:00:00 dbus-daemon
    605 ?        00:00:00 NetworkManager
    622 ?        00:00:00 irqbalance
    627 ?        00:00:00 networkd-dispat
    634 ?        00:00:00 polkitd
    636 ?        00:00:00 power-profiles-
    638 ?        00:00:00 rsyslogd
    643 ?        00:00:01 snapd
    644 ?        00:00:00 switcheroo-cont
    649 ?        00:00:00 systemd-logind
    656 ?        00:00:00 udisksd
    669 ?        00:00:00 wpa_supplicant
    689 ?        00:00:00 avahi-daemon
    712 ?        00:00:00 ModemManager
    715 ?        00:00:00 cupsd
    752 ?        00:00:00 unattended-upgr
    756 ?        00:00:00 dbus
    757 ?        00:00:00 dbus
    758 ?        00:00:00 dbus
    759 ?        00:00:00 dbus
    760 ?        00:00:00 dbus
    761 ?        00:00:00 sshd
    764 ?        00:00:00 gdm3
    772 ?        00:00:00 gdm-session-wor
    786 ?        00:00:00 systemd
    789 ?        00:00:00 (sd-pam)
    792 ?        00:00:00 cups-browsed
    802 ?        00:00:00 kerneloops
    812 ?        00:00:00 rwhod
    813 ?        00:00:00 rwhod
    814 ?        00:00:00 kerneloops
    858 ?        00:00:00 pipewire
    859 ?        00:00:00 pipewire-media-
    860 ?        00:00:00 pulseaudio
    863 ?        00:00:02 snapd-desktop-i
    866 ?        00:00:00 gnome-keyring-d
    870 ?        00:00:00 rtkit-daemon
    878 tty2     00:00:00 gdm-wayland-ses
    881 ?        00:00:00 dbus-daemon
    885 tty2     00:00:00 gnome-session-b
    888 ?        00:00:00 gvfsd
    903 ?        00:00:00 gvfsd-fuse
    940 ?        00:00:00 gnome-session-c
    953 ?        00:00:00 gnome-session-b
    971 ?        00:00:00 at-spi-bus-laun
    975 ?        00:00:22 gnome-shell
    981 ?        00:00:00 dbus-daemon
   1056 ?        00:00:00 xdg-document-po
   1060 ?        00:00:00 xdg-permission-
   1067 ?        00:00:00 fusermount3
   1112 ?        00:00:00 gnome-shell-cal
   1118 ?        00:00:00 evolution-sourc
   1119 ?        00:00:00 upowerd
   1133 ?        00:00:00 goa-daemon
   1145 ?        00:00:00 dconf-service
   1150 ?        00:00:00 evolution-calen
   1156 ?        00:00:00 gvfs-udisks2-vo
   1170 ?        00:00:00 goa-identity-se
   1175 ?        00:00:00 gvfs-gphoto2-vo
   1184 ?        00:00:00 gvfs-mtp-volume
   1190 ?        00:00:00 evolution-addre
   1193 ?        00:00:00 gvfs-afc-volume
   1203 ?        00:00:00 gvfs-goa-volume
   1213 ?        00:00:00 packagekitd
   1242 ?        00:00:00 gvfsd-trash
   1251 ?        00:00:00 gjs
   1253 ?        00:00:00 at-spi2-registr
   1261 ?        00:00:00 sh
   1263 ?        00:00:00 gsd-a11y-settin
   1266 ?        00:00:00 ibus-daemon
   1267 ?        00:00:00 gsd-color
   1268 ?        00:00:00 gsd-datetime
   1269 ?        00:00:00 gsd-housekeepin
   1272 ?        00:00:00 gsd-keyboard
   1276 ?        00:00:00 gsd-media-keys
   1283 ?        00:00:00 gsd-power
   1285 ?        00:00:00 gsd-print-notif
   1286 ?        00:00:00 gsd-rfkill
   1288 ?        00:00:00 gsd-screensaver
   1294 ?        00:00:00 gsd-sharing
   1302 ?        00:00:00 gsd-smartcard
   1310 ?        00:00:00 gsd-sound
   1311 ?        00:00:00 gsd-wacom
   1342 ?        00:00:00 gsd-disk-utilit
   1344 ?        00:00:00 ibus-dconf
   1348 ?        00:00:01 ibus-extension-
   1352 ?        00:00:00 ibus-portal
   1373 ?        00:00:00 evolution-alarm
   1407 ?        00:00:00 gsd-printer
   1428 ?        00:00:00 xdg-desktop-por
   1432 ?        00:00:00 xdg-desktop-por
   1444 ?        00:00:00 ibus-engine-sim
   1447 ?        00:00:00 gvfsd-metadata
   1469 ?        00:00:00 xdg-desktop-por
   1477 ?        00:00:00 colord
   1489 ?        00:00:00 tracker-miner-f
   1514 ?        00:00:00 gjs
   1524 ?        00:00:01 gjs
   1605 ?        00:00:01 gnome-terminal-
   1631 pts/0    00:00:00 bash
   1655 ?        00:00:00 update-notifier
   1785 ?        00:00:00 deja-dup-monito
   1798 pts/0    00:00:00 gnuplot
   1801 pts/1    00:00:00 bash
   1810 pts/1    00:00:00 ps
kristina@kristina-VirtualBox:~$ ps aux | grep gnuplot
kristina    1798  0.0  0.6 115108 27672 pts/0    S+   18:55   0:00 gnuplot
kristina    1822  0.0  0.0  17756  2344 pts/1    S+   18:56   0:00 grep --color=auto gnuplot
kristina@kristina-VirtualBox:~$ killall gnuplot
kristina@kristina-VirtualBox:~$ cat > test.txt
Hello, world!
kristina@kristina-VirtualBox:~$ vim test.txt
kristina@kristina-VirtualBox:~$ cat test.txt
Hello, world!
123!
kristina@kristina-VirtualBox:~$ exit
```
## 11. Выводы
Было выяснено, что в OC UNIX есть множество полезных утилит, которые облегчают работу в этой системе. Были изучены некоторые из них. Освоены навигация в файловой системе, создание, удаление файлов и директорий. В результате выполнения работы, были приобретены навыки, которые будут полезны для выполнения других лабораторных работ.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> ____________________
