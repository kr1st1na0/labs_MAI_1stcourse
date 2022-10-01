# Отчёт по лабораторной работе №2 по курсу “Фундаментальная информатика”

Студент группы: М80-108Б-22 Былькова Кристина Алексеевна, № по списку 2 

Контакты e-mail: kristina.bilckova@yandex.ru

Работа выполнена: «1» октября 2022 г.

Преподаватель: асп. каф. 806 Сахарин Никита Александрович

Входной контроль знаний с оценкой _______________________

Отчет сдан «1» октября 2022 г., итоговая оценка ______

Подпись преподавателя ___________


## 1. Тема
Сети и телекоммуникации в ОС UNIX
## 2. Цель работы
Изучение и освоение удалённых команд UNIX и приобретение навыков, необходимых для выполнения курсовых и лабораторных работ в среде UNIX.
## 3. Задание (вариант № —)
Изучение удалённых команд
## 4. Оборудование:
Процессор: 1,6 GHz 2-ядерный Intel Core i5
ОП: 8 ГБ 2133 MHz LPDDR3
НМД: 256 ГБ  
Адрес: 95.31.164.228 
Монитор: 13,3-дюймовый (2560 х 1600)
Графика: Intel UHD Graphics 617 1536 МБ
## 5. Программное обеспечение:
Операционная система семейства: VirtualBox 6.1.38 - Ubuntu 22.04.01 LTS
Интерпретатор команд: bash версия 4.4.19
Система программирования: не использовалась версия — 
Редактор текстов: emacs версия 25.2.2
Утилиты операционной системы: ssh, sftp
Прикладные системы и программы: -
Местонахождение и имена файлов программ и данных на домашнем компьютере: /home/kristina
## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)
Изучить основы программного обеспечения ОС UNIX
Ввод команд:
1. ls -l/-A/-lAF – ознакомление с содержимым директории
2. hostname -I – ip-адрес терминала, котором ведётся работа 
3. cat – создание нового файла с возможностью записи/копировать
4. rm – удаление
5. mkdir – создание директории
6. rmdir – удаление директории
7. exit – выход
8. ssh - команда для подключения к другой машине
9. scp - удалённое копирование файлов
10. tar -tvf - архивация 
11. tar -xf - разархивация
12. ping - убедиться в доступности сервера в сети
13. sftp - запуск улилиты-клиента для подсоединения к узлу сети, с которым надо осуществить обмен файлами.
14. sftp> get - получить файл с удалённой машины
15. sftp> put - передать файла на удалённую машину
## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
- Изучить литературу по OC UNIX
- Просмотреть демонстрационный материал в лабораторной аудитории
- Освоить удалённые команды OC UNIX
- Научиться удалённо манипулировать с файлами 
- Запротоколировать сеанс

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
Подпись преподавателя _____________________
## 8. Распечатка протокола 
```
kristina@kristina-VirtualBox:~$ ping 192.168.56.102
PING 192.168.56.102 (192.168.56.102) 56(84) bytes of data.
64 bytes from 192.168.56.102: icmp_seq=1 ttl=64 time=1.07 ms
64 bytes from 192.168.56.102: icmp_seq=2 ttl=64 time=1.03 ms
64 bytes from 192.168.56.102: icmp_seq=3 ttl=64 time=0.806 ms
64 bytes from 192.168.56.102: icmp_seq=4 ttl=64 time=0.535 ms
64 bytes from 192.168.56.102: icmp_seq=5 ttl=64 time=0.810 ms
64 bytes from 192.168.56.102: icmp_seq=6 ttl=64 time=0.767 ms
64 bytes from 192.168.56.102: icmp_seq=7 ttl=64 time=0.638 ms
^C
--- 192.168.56.102 ping statistics ---
7 packets transmitted, 7 received, 0% packet loss, time 6078ms
rtt min/avg/max/mdev = 0.535/0.807/1.072/0.178 ms
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
kristina@kristina-VirtualBox:~$ sftp kristina2@192.168.56.102
kristina2@192.168.56.102's password: 
Connected to 192.168.56.102.
sftp> pwd
Remote working directory: /home/kristina2
sftp> ls
arch                                    archive.tar                             
file.txt                                kk                                      
lol.txt                                 mt.tu                                   
snap                                    test.txt                                
testdir                                 Видео                              
Документы                      Загрузки                        
Изображения                  Музыка                            
Общедоступные              Рабочий стол                 
Шаблоны                          
sftp> get file.txt 
Fetching /home/kristina2/file.txt to file.txt
file.txt                                      100%   10     3.1KB/s   00:00    
sftp> put file.txt
Uploading file.txt to /home/kristina2/file.txt
file.txt                                      100%   10     7.1KB/s   00:00    
sftp> ^D
kristina@kristina-VirtualBox:~$ ls
 file.txt   snap    Документы   Изображения   Общедоступные   Шаблоны
 kk         Видео   Загрузки    Музыка       'Рабочий стол'
kristina@kristina-VirtualBox:~$ exit
```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 01.10.22 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
```
-
```
## 11. Выводы
Было выяснено, что в OC UNIX есть возможность удалённого подключения к другим машинам. Были освоены команды, необходимые для установления соединения и удалённых манипуляций с файлами. В результате выполнения лабораторной работы, были приобретены навыки, которые будут полезны для выполнения других лабораторных работх.

Недочёты при выполнении задания могут быть устранены следующим образом: —

Подпись студента _________________


