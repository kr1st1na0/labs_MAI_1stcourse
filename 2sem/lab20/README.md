# Отчёт по лабораторной работе №20 по курсу “Языки и методы программирования”

<b>Студент группы:</b> <ins>М80-108Б-22 Былькова Кристина Алексеевна, № по списку 2</ins>

<b>Контакты e-mail:</b> <ins>kristina.bilckova@yandex.ru</ins>

<b>Работа выполнена:</b> «11» <ins>марта</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>5</ins>

<b>Отчет сдан</b> «11» <ins>марта</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins>5</ins>

<b>Подпись преподавателя:</b> ___________


## 1. Тема
Стандартные утилиты UNIX для обработки файлов
## 2. Цель работы
Изучить основные команды обработки текстовых файлов ОС UNIX.
## 3. Задание (вариант № 2)
Подготовить нетривиальные текстовые файлы для иллюстрации работы 3-х утилит (2 - comm, 12 - uniq, 17 - vi/vim). Запротоколировать подготовленные примеры и иллюстрации работы для 20-ти утилит пакетного режима с распечаткой используемых текстовых файлов.
## 4. Оборудование:
<b>Процессор:</b> AMD Ryzen9-5900HS, 8 ядер

<b>ОП:</b> 16gb

<b>SSD:</b> 1 Tb SSD

<b>Монитор:</b> 15.6" - 2560x1440

<b>Графика:</b> NV GeForce RTX 3080

## 5. Программное обеспечение:
<b>Операционная система семейства:</b> VirtualBox 6.1.38 - Ubuntu 22.04.01 LTS

<b>Интерпретатор команд:</b> bash версия 4.4.19

<b>Система программирования:</b> -

<b>Редактор текстов:</b> -

<b>Утилиты операционной системы:</b> cmp, comm, wc, diff, grep, sort, tail, tee, uniq, od, sum, cut, vi/vim, tar, gzip, ed, bzip2, head, iconv, touch, df, paste, mktemp

<b>Прикладные системы и программы:</b> -

<b>Местонахождение и имена файлов программ и данных на домашнем компьютере:</b> /home/kristina

## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)

| Команда |  Базовый синтакис | Флаги | Описание |
| ------ | ------ | ------ | ------ |
| comm | comm [параметры] <файл_1> <файл_2> | "-1" - вывод уникальных строк из второго файла; "-2" - вывод уникальных строк из первого файла; "-3" - вывод повторяющихся строк; "-23" - строки, встречающиеся только в первом файле; "-13" - строки, встречающиеся только во втором файле; "-12" - строки, встречающиеся в обоих файлах | Команда ищет одинаковые и разные строки в файлах. отсортированных в лексикографическом порядке |
| uniq | uniq [параметры] <файл_источник>_<файл для_записи> | "-u" - выводит исключительно те строки, у которых нет повторов; "-d" - если какая-либо строка повторяется несколько раз, она будет выведена лишь единожды; "-D" - выводит только повторяющиеся строки; "--group" - выводит весь текст, при этом разделяя группы строк пустой строкой; "-c" - в начале каждой строки выводит число, которое обозначает количество повторов; "-i" - при сравнении не будет иметь значение регистр, в котором напечатаны символы; | Команда для поиска повторяющихся строк из текстового файла с возможностью их удаления и вывода |
| vi/vim | vim [параметры] <файл> | "+номер" - переместить курсор к указанной строке после запуска; "+/шаблон" - выполнить поиск по шаблону и переместить курсор к первому вхождению; "+команда" - выполнить команду после запуска программы; "-b" - двоичный режим, для редактирования исполняемых файлов; "-d" - режим поиска различий в файлах, нужно указать несколько файлов для открытия; "-g" - графический режим; "-n" - не использовать автосохранение для восстановления файла при сбое; "-R" - режим только для чтения; "-w" - сохранить все действия в файл; "-x" - шифровать файл при записи; "-C" - режим совместимости с Vi; | Текстовый редактор |

<b>Vim</b>
1. Команды для перемещения:
- ```h``` - на один символ влево
- ```l``` - на один символ вправо
- ```j``` - на одну строку вниз
- ```k``` - на одну строку вверх
- ```w``` - на слово вправо
- ```b``` - на слово влево
- ```H``` - перейти в низ экрана
- ```G``` - перейти в конец файла
- ```gg``` - перейти в начало файла
- ```<номер>G``` - перейти к конкретной строке
2. Команды для редактирования:
- ```i``` - вставить текст с позиции курсора, символ под курсором будет заменен
- ```l``` - вставить текст в начало строки
- ```a``` - добавить текст начиная от позиции курсора
- ```o``` - вставить новую строку после этой и начать редактирование
- ```O``` - вставить новую строку перед этой и начать редактирование
3. Удаление символов и строк:
- ```d``` - удалить символ
- ```dd``` - удалить всю строку
- ```D``` - удалить символы начиная от курсора и до конца строки
4. Замена символов:
- ```r``` - заменить текущий символ
- ```R``` - заменить несколько символов
5. Отмена и повтор действий:
- ```u``` - отменить последнее действие
- ```U``` - отменить последнее действие в текущей строке
- ```.``` - повторить последнее действие
- ```Ctrl+r``` - отменить отмену последнего действия
6. Командная строка Vim:
- ```:w``` - сохранить файл
- ```:q``` - закрыть редактор
- ```:q!``` - закрыть редактор без сохранения
- ```:e файл``` - прочитать содержимое файла в позицию курсора;
- ```:r файл``` - вставить в содержимое файла в следующую строку;
- ```:r!``` - выполнить команду оболочки и вставить ответ в редактор;
- ```:set переменная=значение``` - установить значение переменной, например, tabstop=4, или set number, с помощью этой команды можно управлять многими аспектами работы vim.
- ```:buffers``` - посмотреть открытые файлы;
- ```:reg``` - посмотреть содержимое буферов обмена.
7. Выделение и буфер обмена:
- ```y``` - скопировать в буфер обмена;
- ```yy``` or ```Y``` - скопировать строку в буфер обмена;
- ```x``` - вырезать в буфер обмена;
- ```p``` - вставить из буфера обмена.
8. Поиск и замена в Vim:
- ```f``` - найти один символ;
- ```/``` - искать несколько символов;
- ```n``` - найти следующее вхождение;
- ```N``` - найти предыдущее вхождение.

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию].

1. ```cmp``` – сравнение двух файлов байт за байтом
2. ```wc``` – обработка входного потока или файла
3. ```diff``` – определеяет изменения в файлах, которые необходимо сделать, чтобы они стали идентичными
4. ```grep``` – позволяет фильтровать и сортировать содержимое текстовых файлов 
5. ```sort``` – сортировка текста
6. ```tail``` – выводит последние N строк файла (по умолчанию - последние 10 строк)
7. ```tee``` – запись вывода любой команды в один или несколько файлов
8. ```od``` – печать файла в восьмеричном формате (по умолчанию)
9. ```sum``` – подсчет контрольной суммы и блоков в файлеы
10. ```cut``` – позволяет вырезать части строк из указанных файлов
11. ```tar``` – распаковка архива tar Linux с выводом файлов на экран
12. ```gzip``` – архивирование файлов
13. ```ed``` – текстовый редактор
14. ```bzip2``` – архивирование файлов, более эффективная, но работает медленнее
15. ```head``` – выводит первые N строк файла (по умолчанию - первые 10 строк)
16. ```iconv``` – преобразование текстового файла из одной кодировки в другую
17. ```touch``` – создание пустого файла, изменение модификации и времени доступа для любого файла
18. ```df``` – получение полной сводной информации об использовании доступного и используемого дискового пространства файловой системы
19. ```paste``` – объединение соответствующих строк файлов по горизонтали
20. ```mktemp``` – создание временных файлов или каталогов

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя:</b> _____________________

## 8. Распечатка протокола 

```
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ cat file1.txt
001
002
003
004
005
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ cat file2.txt
000
001
003
005
007
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ comm file1.txt file2.txt
	000
		001
002
		003
004
		005
	007
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ comm -1 file1.txt file2.txt
000
	001
	003
	005
007
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ comm -2 file1.txt file2.txt
	001
002
	003
004
	005
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ comm -3 file1.txt file2.txt
	000
002
004
	007
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ comm -23 file1.txt file2.txt
002
004
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ comm -13 file1.txt file2.txt
000
007
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ comm -12 file1.txt file2.txt
001
003
005
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ cat file3.txt
a
a
b
b
c
d
d
d
e
f
o
p
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ uniq file3.txt
a
b
c
d
e
f
o
p
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ uniq -c file3.txt
      2 a
      2 b
      1 c
      3 d
      1 e
      1 f
      1 o
      1 p
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ uniq -u file3.txt
c
e
f
o
p
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ uniq -D file3.txt
a
a
b
b
d
d
d
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ uniq --group file3.txt
a
a

b
b

c

d
d
d

e

f

o

p
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ cat file3.txt
a
A
b
B
B
c
d
d
d
e
F
o
p
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ uniq -i file3.txt
a
b
c
d
e
F
o
p
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ touch file6.txt
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ cat file6.txt
sjdn
qpwpwo
kdkdl
qwetyu
qlxsl
vclsl
clksd
iowep
cmdkfm
sjdcjds
fkmkm
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ vim -R file6.txt
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ vim -d file1.txt file2.txt
Файлов для редактирования: 2
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ vim file6.txt
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ cmp file1.txt file2.txt
file1.txt file2.txt различаются: байт 3, строка 1
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ cmp -b file1.txt file2.txt
file1.txt file2.txt различаются: байт 3, строка 1 равен  61 1  60 0
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ diff -q file1.txt file2.txt
Файлы file1.txt и file2.txt различаются
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ diff -y file1.txt file2.txt
							      >	000
001								001
002							      <
003								003
004							      <
005								005
							      >	007
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ grep -c op file3.txt
3
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ grep -n op file3.txt
2:oppoo
10:oppoo
12:op
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ touch file4.txt
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ touch --version
touch (GNU coreutils) 8.32
Copyright (C) 2020 Free Software Foundation, Inc.
Лицензия GPLv3+: GNU GPL версии 3 или новее <https://gnu.org/licenses/gpl.html>.
Это свободное ПО: вы можете изменять и распространять его.
Нет НИКАКИХ ГАРАНТИЙ в пределах действующего законодательства.

Авторы программы — Paul Rubin, Arnold Robbins, Jim Kingdon,
David MacKenzie и Randy Smith.
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ cat file4.txt
875
3039
1327
1
38
292
3747
500000
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ sort file4.txt
1
1327
292
3039
3747
38
500000
875
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ sort -n file4.txt
1
38
292
875
1327
3039
3747
500000
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ cat file4.txt
875
3039
1327
1
38
292
3747
500000
3883
403020
1393939
494849
102002
494848
393921
746789
34567890
22
39
59
367458
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ tail file4.txt
494849
102002
494848
393921
746789
34567890
22
39
59
367458
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ tail -n 5 file4.txt
34567890
22
39
59
367458
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ touch file5.txt
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ cat file5.txt
45
28
90
10
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ tee -a file5.txt
gg
gg
^C
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ cat file5.txt
45
28
90
10
gg
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ od file5.txt
0000000 032464 031012 005070 030071 030412 005060 063547 000012
0000017
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ od -b file5.txt
0000000 064 065 012 062 070 012 071 060 012 061 060 012 147 147 012
0000017
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ od -c file5.txt
0000000   4   5  \n   2   8  \n   9   0  \n   1   0  \n   g   g  \n
0000017
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ sum file5.txt
58805     1
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ cut -c 1 file5.txt
4
2
9
1
g
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ cut -c 2 file5.txt
5
8
0
0
g
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ cat file4.txt
875
3039
1327
1
38
292
3747
500000
3883
403020
1393939
494849
102002
494848
393921
746789
34567890
22
39
59
367458
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ head file4.txt
875
3039
1327
1
38
292
3747
500000
3883
403020
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ head -n 5 file4.txt
875
3039
1327
1
38
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ gzip file5.txt
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ ls
file1.txt  file2.txt  file3.txt  file4.txt  file5.txt.gz  lab20.txt
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ gzip -d file5.txt
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ ls
file1.txt  file2.txt  file3.txt  file4.txt  file5.txt  lab20.txt
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ tar --totals -cvf ar.tar file1.txt file2.txt
file1.txt
file2.txt
Всего записано байт: 10240 (10KiB, 54MiB/s)
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ ls
ar.tar  file1.txt  file2.txt  file3.txt  file4.txt  file5.txt  lab20.txt
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ tar -tf ar.tar
file1.txt
file2.txt
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ tar -xvf ar.tar
file1.txt
file2.txt
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ ls
ar.tar  file1.txt  file2.txt  file3.txt  file4.txt  file5.txt  lab20.txt
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ cat file3.txt
fdjkjfjf
oppoo
dkdkd
k
p
a
b
k
ol
oppoo
ppooo
op
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ iconv -f ascii -t KOI8-R file3.txt -o outfile.txt
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ cat outfile.txt
fdjkjfjf
oppoo
dkdkd
k
p
a
b
k
ol
oppoo
ppooo
op
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ ed file3.txt
49
5
p
12
op
q
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ cat file1.txt
001
002
003
004
005
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ ed
a
9999999999
0
.
p
0
,p
9999999999
0
f file1.txt
file1.txt
w
13
q
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ cat file1.txt
9999999999
0
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ wc -c file1.txt
13 file1.txt
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ wc -l file1.txt
2 file1.txt
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ wc -w file1.txt
2 file1.txt
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ wc file1.txt
 2  2 13 file1.txt
 kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ df
 Файл.система   1K-блоков Использовано Доступно Использовано% Cмонтировано в
 tmpfs             401792         1528   400264            1% /run
 /dev/sda3       25106692     15141964  8664044           64% /
 tmpfs            2008952        19608  1989344            1% /dev/shm
 tmpfs               5120            4     5116            1% /run/lock
 /dev/sda2         524252         5364   518888            2% /boot/efi
 tmpfs             401788         2428   399360            1% /run/user/1000
 /dev/sr0           62390        62390        0          100% /media/kristina/VBox_GAs_6.1.38
 kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ paste file1.txt file2.txt
 001	000
 002	001
 003	003
 004	005
 005	007
 kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ paste -d '_' file1.txt file2.txt
 001_000
 002_001
 003_003
 004_005
 005_007
 kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ ls
 file1.txt  file2.txt  file3.txt  file4.txt  file5.txt  lab20.txt  outfile.txt
 kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ bzip2 file1.txt file2.txt
 kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ ls
 file1.txt.bz2  file2.txt.bz2  file3.txt  file4.txt  file5.txt  lab20.txt  outfile.txt
 kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ bzip2 -d file1.txt.bz2 file2.txt.bz2
 kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ ls
 file1.txt  file2.txt  file3.txt  file4.txt  file5.txt  lab20.txt  outfile.txt
 kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ mktemp
/tmp/tmp.eQWijQrHuM
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ mktemp -d
/tmp/tmp.ELwVswHNGj
kristina@kristina-VirtualBox:~/Рабочий стол/labs/lab20$ ls -al /tmp
итого 92
drwxrwxrwt 20 root     root     4096 мар 11 11:17 .
drwxr-xr-x 20 root     root     4096 окт  5 00:29 ..
-rw-rw-r--  1 kristina kristina  104 мар  9 22:16 66fa1c4d548d4493266618f63c5b1931-{87A94AB0-E370-4cde-98D3-ACC110C5967D}
srwxrwxr-x  1 kristina kristina    0 мар  9 22:15 atom-17b01bb56723.sock
srwxrwxr-x  1 kristina kristina    0 мар  9 22:16 f1dad0cd9295c76ca9093399f4fa16f2-{87A94AB0-E370-4cde-98D3-ACC110C5967D}
drwxrwxrwt  2 root     root     4096 мар  9 22:14 .font-unix
drwxrwxrwt  2 root     root     4096 мар  9 22:14 .ICE-unix
drwx------  4 root     root     4096 мар  9 22:20 snap-private-tmp
drwx------  3 root     root     4096 мар  9 22:14 systemd-private-151f65e663924ee599970663a871a14c-colord.service-gkRG5e
drwx------  3 root     root     4096 мар  9 22:14 systemd-private-151f65e663924ee599970663a871a14c-ModemManager.service-xV5qjw
drwx------  3 root     root     4096 мар  9 22:14 systemd-private-151f65e663924ee599970663a871a14c-power-profiles-daemon.service-MsgjwD
drwx------  3 root     root     4096 мар  9 22:14 systemd-private-151f65e663924ee599970663a871a14c-switcheroo-control.service-AM5SCD
drwx------  3 root     root     4096 мар  9 22:14 systemd-private-151f65e663924ee599970663a871a14c-systemd-logind.service-ZjdvDb
drwx------  3 root     root     4096 мар  9 22:14 systemd-private-151f65e663924ee599970663a871a14c-systemd-oomd.service-fwmrDV
drwx------  3 root     root     4096 мар  9 22:14 systemd-private-151f65e663924ee599970663a871a14c-systemd-resolved.service-Eyfjhx
drwx------  3 root     root     4096 мар  9 22:14 systemd-private-151f65e663924ee599970663a871a14c-systemd-timesyncd.service-7jbDTU
drwx------  3 root     root     4096 мар  9 22:14 systemd-private-151f65e663924ee599970663a871a14c-upower.service-N2tnJ3
drwxrwxrwt  2 root     root     4096 мар  9 22:14 .Test-unix
drwx------  2 kristina kristina 4096 мар 11 11:17 tmp.ELwVswHNGj
-rw-------  1 kristina kristina    0 мар 11 11:17 tmp.eQWijQrHuM
drwx------  2 kristina kristina 4096 мар 11 11:16 tracker-extract-3-files.1000
drwxrwxrwt  2 root     root     4096 мар  9 22:14 VMwareDnD
-r--r--r--  1 kristina kristina   11 мар  9 22:14 .X0-lock
drwxrwxrwt  2 root     root     4096 мар  9 22:14 .X11-unix
-r--r--r--  1 kristina kristina   11 мар  9 22:14 .X1-lock
drwxrwxrwt  2 root     root     4096 мар  9 22:14 .XIM-unix
```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 11.03.23 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы

<b>Защита</b>

- [Задача во время контеста](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427386/submission/193848037)
- [Дорешка](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427386/submission/197005255)

## 11. Выводы
Было выяснено, что OC UNIX не только имеет прекрасные средства программирования, но и обладает массой простых утилит, позволяющих выполнять многие сложные работы с файлами без программирования путем последовательного и конвейерного выполнения этих программ. Были изучены некоторые из них. В результате выполнения работы, были приобретены навыки, которые будут полезны для выполнения других лабораторных работ и курсовых проектов.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> _________________


