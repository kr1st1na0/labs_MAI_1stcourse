# Отчёт по лабораторной работе №3 по курсу “Фундаментальная информатика”

</b>Студент группы:</b> <ins>М80-108Б-22 Былькова Кристина Алексеевна, № по списку 2<ins>

</b>Контакты e-mail:</b> <ins>kristina.bilckova@yandex.ru<ins>

</b>Работа выполнена:</b> «1» <ins>октября<ins> <ins>2022<ins> г.

</b>Преподаватель:</b> асп. каф. 806 Сахарин Никита Александрович

</b>Входной контроль знаний с оценкой:</b> <ins>5 (отлично)</ins>

<b>Отчет сдан<b> «1» <ins>октября<ins> <ins>2022<ins> г., <b>итоговая оценка</b> <ins>5 (отлично)</ins>

<b>Подпись преподавателя:</b> ___________


## 1. Тема
Сети и телекоммуникации в ОС UNIX
## 2. Цель работы
Изучение и освоение удалённых команд UNIX и приобретение навыков, необходимых для выполнения курсовых и лабораторных работ в среде UNIX.
## 3. Задание (вариант № —)
Изучение удалённых команд
## 4. Оборудование:
<b>Процессор</b>: 1,6 GHz 2-ядерный Intel Core i5-8210Y
<b>ОП</b>: 8 ГБ 2133 MHz LPDDR3
<b>SSD</b>: 256 ГБ  
<b>Адрес</b>: 95.31.164.228 
<b>Монитор</b>: 13,3-дюймовый (2560 х 1600)
<b>Графика</b>: Intel UHD Graphics 617 1536 МБ
## 5. Программное обеспечение:
<b>Операционная система семейства:</b> VirtualBox 6.1.38 - Ubuntu 22.04.01 LTS
<b>Интерпретатор команд:</b> bash версия 4.4.19
<b>Система программирования:</b> не использовалась версия — 
<b>Редактор текстов:</b> emacs версия 25.2.2
<b>Утилиты операционной системы:</b> ssh, iconv
<b>Прикладные системы и программы:</b> gnuplot
<b>Местонахождение и имена файлов программ и данных на домашнем компьютере:</b> /home/kristina
## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)
Изучить основы программного обеспечения ОС UNIX
Ввод команд:
1. ```ls -l/-A/-lAF``` – ознакомление с содержимым директории
2. ```hostname -I``` – ip-адрес терминала, котором ведётся работа 
3. ```cat``` – создание нового файла с возможностью записи/копировать
4. ```rm``` – удаление
5. ```mkdir``` – создание директории
6. ```rmdir``` – удаление директории
7. ```exit``` – выход
8. ```ssh``` - команда для подключения к другой машине
9. ```scp``` - удалённое копирование файлов
10. ```tar -tvf``` - архивация 
11. ```tar -xf``` - разархивация
12. ```dos2unix``` - преобразование символов расширенного набора символов DOS в соответствующие символы стандарта ISO
13. ```xxd``` - вывод в шестнадцатеричной системе
14. ```iconv``` - преобразование текста из одной кодировки в другую
15. ```ping``` - убедиться в доступности сервера в сети
16. ```sftp``` - запуск улилиты-клиента для подсоединения к узлу сети, с которым надо осуществить обмен файлами
17. ```sftp> get``` - получить файл с удалённой машины
18. ```sftp> put``` - передать файла на удалённую машину

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
- Изучить литературу по OC UNIX
- Просмотреть демонстрационный материал в лабораторной аудитории
- Освоить удалённые команды OC UNIX
- Научиться удалённо манипулировать с файлами 
- Запротоколировать сеанс

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
</b>Подпись преподавателя</b> _____________________
## 8. Распечатка протокола 
```
kristina@kristina-VirtualBox:~$ hostname -I
192.168.56.101
kristina@kristina-VirtualBox:~$ ls
 snap   Видео   Документы   Загрузки   Изображения   Музыка   Общедоступные  'Рабочий стол'   Шаблоны
kristina@kristina-VirtualBox:~$ cat > file.txt
test file
kristina@kristina-VirtualBox:~$ ls
 file.txt   Видео       Загрузки      Музыка         'Рабочий стол'
 snap       Документы   Изображения   Общедоступные   Шаблоны
kristina@kristina-VirtualBox:~$ mkdir kk
kristina@kristina-VirtualBox:~$ ls
 file.txt   snap    Документы   Изображения   Общедоступные   Шаблоны
 kk         Видео   Загрузки    Музыка       'Рабочий стол'
kristina@kristina-VirtualBox:~$ cp file.txt kk
kristina@kristina-VirtualBox:~$ ls
 file.txt   snap    Документы   Изображения   Общедоступные   Шаблоны
 kk         Видео   Загрузки    Музыка       'Рабочий стол'
kristina@kristina-VirtualBox:~$ cd kk
kristina@kristina-VirtualBox:~/kk$ ls
file.txt
kristina@kristina-VirtualBox:~/kk$ cd .. 
kristina@kristina-VirtualBox:~$ ssh kristina2@192.168.56.102
kristina2@192.168.56.102's password: 
Welcome to Ubuntu 22.04.1 LTS (GNU/Linux 5.15.0-48-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

131 обновление может быть применено немедленно.
38 из этих обновлений, являются стандартными обновлениями безопасности.
Чтобы просмотреть дополнительные обновления выполните: apt list --upgradable

Last login: Tue Sep 27 15:29:15 2022 from 127.0.0.1
kristina2@kristina2-VirtualBox:~$ ls
 snap    Документы   Изображения   Общедоступные   Шаблоны
 Видео   Загрузки    Музыка       'Рабочий стол'
kristina2@kristina2-VirtualBox:~$ cat > test.txt
Hello, world!
kristina2@kristina2-VirtualBox:~$ ls
 snap       Видео       Загрузки      Музыка         'Рабочий стол'
 test.txt   Документы   Изображения   Общедоступные   Шаблоны
kristina2@kristina2-VirtualBox:~$ scp /home/kristina2/test.txt kristina@192.168.56.101:/home/kristina
kristina@192.168.56.101's password: 
test.txt                                         100%   14     5.9KB/s   00:00    
kristina2@kristina2-VirtualBox:~$ mkdir testdir
kristina2@kristina2-VirtualBox:~$ cat > lol.txt
lol
kristina2@kristina2-VirtualBox:~$ ls
 lol.txt   testdir    Видео       Загрузки      Музыка         'Рабочий стол'
 snap      test.txt   Документы   Изображения   Общедоступные   Шаблоны
kristina2@kristina2-VirtualBox:~$ 
kristina2@kristina2-VirtualBox:~$ cp lol.txt testdir
kristina2@kristina2-VirtualBox:~$ cd testdir
kristina2@kristina2-VirtualBox:~/testdir$ ls
lol.txt
kristina2@kristina2-VirtualBox:~/testdir$ cd ..
kristina2@kristina2-VirtualBox:~$ scp -r /home/kristina2/testdir kristina@192.168.56.101:/home/kristina
kristina@192.168.56.101's password: 
lol.txt                                          100%    4     2.0KB/s   00:00
kristina2@kristina2-VirtualBox:~$ ssh kristina@192.168.56.101 "ls -1 ~"
kristina@192.168.56.101's password: 
file.txt
test.txt
kk
snap
testdir
Видео
Документы
Загрузки
Изображения
Музыка
Общедоступные
Рабочий стол
Шаблоны
kristina2@kristina2-VirtualBox:~$ ssh kristina@192.168.56.101 "ls -1 ~/testdir"
kristina@192.168.56.101's password: 
lol.txt
kristina2@kristina2-VirtualBox:~$ mkdir arch
kristina2@kristina2-VirtualBox:~$ tar -cf archive.tar arch
kristina2@kristina2-VirtualBox:~$ ls
 arch          snap       Видео       Изображения    'Рабочий стол'
 archive.tar   testdir    Документы   Музыка          Шаблоны
 lol.txt       test.txt   Загрузки    Общедоступные
kristina2@kristina2-VirtualBox:~$ tar -tvf archive.tar
drwxrwxr-x kristina2/kristina2 0 2022-09-27 17:56 arch/
kristina2@kristina2-VirtualBox:~$ scp /home/kristina2/archive.tar kristina@192.168.56.101:/home/kristina
kristina@192.168.56.101's password: 
archive.tar                                      100%   10KB   3.4MB/s   00:00 
kristina2@kristina2-VirtualBox:~$ exit
выход
Connection to 192.168.56.102 closed.
kristina@kristina-VirtualBox:~$ ls
 archive.tar  test.txt  kk     testdir   Документы   Изображения   Общедоступные   Шаблоны
 file.txt      snap    Видео     Загрузки    Музыка       'Рабочий стол'
kristina@kristina-VirtualBox:~$ cat test.txt
Hello, world!
kristina@kristina-VirtualBox:~$ cd testdir
kristina@kristina-VirtualBox:~/testdir$ ls
lol.txt
kristina@kristina-VirtualBox:~/testdir$ cat lol.txt
lol
kristina@kristina-VirtualBox:~/testdir$ cd ..
kristina@kristina-VirtualBox:~$ tar -xf archive.tar
kristina@kristina-VirtualBox:~$ ls
 arch          test.txt    kk        Видео       Изображения    'Рабочий стол'
 archive.tar   snap      Документы   Музыка          Шаблоны
 file.txt      testdir   Загрузки    Общедоступные
kristina@kristina-VirtualBox:~$ rmdir arch
kristina@kristina-VirtualBox:~$ rm archive.tar
kristina@kristina-VirtualBox:~$ rm test.txt
kristina@kristina-VirtualBox:~$ ls
 file.txt   test.txt    snap      Видео       Загрузки      Музыка         'Рабочий стол'
 kk         testdir   Документы   Изображения   Общедоступные   Шаблоны
kristina@kristina-VirtualBox:~$ cd testdir
kristina@kristina-VirtualBox:~/testdir$ ls
lol.txt
kristina@kristina-VirtualBox:~/testdir$ rm lol.txt
kristina@kristina-VirtualBox:~/testdir$ cd ..
kristina@kristina-VirtualBox:~$ rmdir testdir
kristina@kristina-VirtualBox:~$ ls
 file.txt   snap    Документы   Изображения   Общедоступные   Шаблоны
 kk         Видео   Загрузки    Музыка       'Рабочий стол'
kristina@kristina-VirtualBox:~$ ssh kristina2@192.168.56.102
kristina2@192.168.56.102's password: 
Welcome to Ubuntu 22.04.1 LTS (GNU/Linux 5.15.0-48-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

131 обновление может быть применено немедленно.
38 из этих обновлений, являются стандартными обновлениями безопасности.
Чтобы просмотреть дополнительные обновления выполните: apt list --upgradable

Last login: Tue Sep 27 17:32:33 2022 from 192.168.56.101
kristina2@kristina2-VirtualBox:~$ ls
 arch          snap       Видео       Изображения    'Рабочий стол'
 archive.tar   testdir    Документы   Музыка          Шаблоны
 lol.txt       test.txt   Загрузки    Общедоступные
kristina2@kristina2-VirtualBox:~$ scp kristina@192.168.56.101:~/file.txt ~
kristina@192.168.56.101's password: 
file.txt                                         100%   10     5.6KB/s   00:00    
kristina2@kristina2-VirtualBox:~$ ls
 arch          lol.txt   test.txt    Загрузки      Общедоступные
 archive.tar   snap      Видео       Изображения  'Рабочий стол'
 file.txt      testdir   Документы   Музыка        Шаблоны
kristina2@kristina2-VirtualBox:~$ cat test.txt
Hello, world!
kristina2@kristina2-VirtualBox:~$ scp -r kristina@192.168.56.101:~/kk ~
kristina@192.168.56.101's password: 
file.txt                                         100%   10     7.0KB/s   00:00  
kristina2@kristina2-VirtualBox:~$ ls
 arch          kk        testdir    Документы     Музыка          Шаблоны
 archive.tar   lol.txt   test.txt   Загрузки      Общедоступные
 file.txt      snap      Видео      Изображения  'Рабочий стол'
kristina2@kristina2-VirtualBox:~$ cd kk
kristina2@kristina2-VirtualBox:~/kk$ ls
file.txt
kristina2@kristina2-VirtualBox:~/kk$ cat file.txt
test file
kristina2@kristina2-VirtualBox:~/kk$ cd ..
kristina2@kristina2-VirtualBox:~$ exit
выход
Connection to 192.168.56.102 closed.
kristina@kristina-VirtualBox:~$ exit
```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 01.10.22 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
```
kristina@kristina-VirtualBox:~$ ssh kristina2@192.168.56.102
kristina2@192.168.56.102's password: 
Welcome to Ubuntu 22.04.1 LTS (GNU/Linux 5.15.0-48-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage
 
131 обновление может быть применено немедленно.
38 из этих обновлений, являются стандартными обновлениями безопасности.
Чтобы просмотреть дополнительные обновления выполните: apt list --upgradable

Last login: Sat Oct  1 17:05:50 2022 from 192.168.56.101
kristina2@kristina2-VirtualBox:~$ ls
 snap    Документы   Изображения   Общедоступные   Шаблоны
 Видео   Загрузки    Музыка       'Рабочий стол'
kristina2@kristina2-VirtualBox:~$ cat > file.txt
test file
kristina2@kristina2-VirtualBox:~$ scp /home/kristina2/file.txt kristina@192.168.56.101:/home/kristina
kristina@192.168.56.101's password: 
file.txt                                      100%   10     3.2KB/s   00:00    
kristina2@kristina2-VirtualBox:~$ exit
выход
Connection to 192.168.56.102 closed.
kristina@kristina-VirtualBox:~$ ls
 1       file.txt   snap    Документы   Изображения   Общедоступные   Шаблоны
 1.tar   kk         Видео   Загрузки    Музыка       'Рабочий стол'
kristina@kristina-VirtualBox:~$ ^C
kristina@kristina-VirtualBox:~$ touch k.txt
kristina@kristina-VirtualBox:~$ ls
 1          kk      Видео       Изображения    'Рабочий стол'
 1.tar      k.txt   Документы   Музыка          Шаблоны
 file.txt   snap    Загрузки    Общедоступные
kristina@kristina-VirtualBox:~$ scp /home/kristina/k.txt kristina2@192.168.56.102:~
kristina2@192.168.56.102's password: 
k.txt                                         100%    0     0.0KB/s   00:00    
kristina@kristina-VirtualBox:~$ ssh kristina2@192.168.56.102
kristina2@192.168.56.102's password: 
Welcome to Ubuntu 22.04.1 LTS (GNU/Linux 5.15.0-48-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

131 обновление может быть применено немедленно.
38 из этих обновлений, являются стандартными обновлениями безопасности.
Чтобы просмотреть дополнительные обновления выполните: apt list --upgradable

Last login: Sat Oct  1 17:08:40 2022 from 192.168.56.101
kristina2@kristina2-VirtualBox:~$ ls
 file.txt   snap    Документы   Изображения   Общедоступные   Шаблоны
 k.txt      Видео   Загрузки    Музыка       'Рабочий стол'
kristina2@kristina2-VirtualBox:~$ exit
выход
Connection to 192.168.56.102 closed.
kristina@kristina-VirtualBox:~$ exit

kristina@kristina-VirtualBox:~$ iconv -t utf-16 > file3.txt
test file aaa 23 io
kristina@kristina-VirtualBox:~$ xxd file3.txt
00000000: fffe 7400 6500 7300 7400 2000 6600 6900  ..t.e.s.t. .f.i.
00000010: 6c00 6500 2000 6100 6100 6100 2000 3200  l.e. .a.a.a. .2.
00000020: 3300 2000 6900 6f00 0a00                 3. .i.o...
kristina@kristina-VirtualBox:~$ iconv -t utf-8 > file2.txt
test file aaa 23 io
kristina@kristina-VirtualBox:~$ xxd file2.txt
00000000: 7465 7374 2066 696c 6520 6161 6120 3233  test file aaa 23
00000010: 2069 6f0a                                 io.
kristina@kristina-VirtualBox:~$ mkdir 1
kristina@kristina-VirtualBox:~$ mkdir 2
kristina@kristina-VirtualBox:~$ mkdir 3
kristina@kristina-VirtualBox:~$ ls
 1   3           file3.txt   snap    Документы   Изображения   Общедоступные   Шаблоны
 2   file2.txt   kk          Видео   Загрузки    Музыка       'Рабочий стол'
kristina@kristina-VirtualBox:~$ mv file3.txt 3
kristina@kristina-VirtualBox:~$ mv file2.txt 2
kristina@kristina-VirtualBox:~$ ls
 1   3    snap    Документы   Изображения   Общедоступные   Шаблоны
 2   kk   Видео   Загрузки    Музыка       'Рабочий стол'
kristina@kristina-VirtualBox:~$ mv 2 1
kristina@kristina-VirtualBox:~$ mv 3 1
kristina@kristina-VirtualBox:~$ ls
 1    snap    Документы   Изображения   Общедоступные   Шаблоны
 kk   Видео   Загрузки    Музыка       'Рабочий стол'
kristina@kristina-VirtualBox:~$ cd 1
kristina@kristina-VirtualBox:~/1$ ls
2  3
kristina@kristina-VirtualBox:~/1$ cd 2
kristina@kristina-VirtualBox:~/1/2$ ls
file2.txt
kristina@kristina-VirtualBox:~/1/2$ cd ..
kristina@kristina-VirtualBox:~/1$ cd ..
kristina@kristina-VirtualBox:~$ tar -cf 1.tar 1
kristina@kristina-VirtualBox:~$ ls
 1       kk     Видео       Загрузки      Музыка         'Рабочий стол'
 1.tar   snap   Документы   Изображения   Общедоступные   Шаблоны
kristina@kristina-VirtualBox:~$ scp /home/kristina/1.tar kristina2@192.168.56.102:~
kristina2@192.168.56.102's password: 
1.tar                                                         100%   10KB   6.0MB/s   00:00    
kristina@kristina-VirtualBox:~$ ls
 1       kk     Видео       Загрузки      Музыка         'Рабочий стол'
 1.tar   snap   Документы   Изображения   Общедоступные   Шаблоны
kristina@kristina-VirtualBox:~$ cd 1
kristina@kristina-VirtualBox:~/1$ cd 2
kristina@kristina-VirtualBox:~/1/2$ ls
file2.txt
kristina@kristina-VirtualBox:~/1/2$ dos2unix file2.txt
dos2unix: converting file file2.txt to Unix format...
kristina@kristina-VirtualBox:~/1/2$ ls
file2.txt
kristina@kristina-VirtualBox:~$ exit
```
## 11. Выводы
Было выяснено, что в OC UNIX есть возможность удалённого подключения к другим машинам. Были освоены команды, необходимые для установления соединения и удалённых манипуляций с файлами. В результате выполнения лабораторной работы, были приобретены навыки, которые будут полезны для выполнения других лабораторных работ.

Недочёты при выполнении задания могут быть устранены следующим образом: —

</b>Подпись студента</b> _________________


