# Отчёт по лабораторной работе №10 по курсу "Фундаментальная информатика"

<b>Студент группы:</b> <ins>М80-108Б-22 Былькова Кристина Алексеевна, № по списку 2</ins> 

<b>Контакты e-mail:</b> <ins>kristina.bilckova@yandex.ru</ins>

<b>Работа выполнена:</b> «29» <ins>октября</ins> <ins>2022</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «29» <ins>октября</ins> <ins>2022</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ________________

## 1. Тема
Отладчик системы программирования ОС UNIX
## 2. Цель работы
Научиться отлаживать простейшие программы, написанные на языке Си.
## 3. Задание (вариант № -)
Написать простейшую программу на языке и отладить её.
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

<b>Редактор текстов:</b> emacs версия 25.2.2

<b>Утилиты операционной системы:</b> -

<b>Прикладные системы и программы:</b> gcc, gdb 

<b>Местонахождение и имена файлов программ и данных на домашнем компьютере:</b> /home/kristina

## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)

| gdb |  Описание команды |
| ------ | ------ |
| help [раздел] | Подсказка по разделу отладчика. Без параметров выводит список разделов. |
| list [имя фукнции/файла:] [номер строки] | Распечатка текста функции/процедуры/файла или всей программы, начиная с указанной строки. По умолчанию распечатываются 10 строк программы. Распечатываемый файл становится текущим файлом исходного текста отлаживаемой программы. |
| break [номер строки/имя функции] | Задание точки остановки на строке/функции текущего исходного файла программы. |
| run [параметры] | Запуск программы на выполнение. Могут указываться необязательные параметры командной строки и операции перенаправления ввода-вывода. gdb запоминает параметры и подставляет их для дальнейших вызовах run. |
| set args [параметры] | Предварительная установка параметров командной строки. |
| show args | Вывод параметров командной строки. |
| print [выражение] | Печать значения выражения, которое может включать и переменные, и вызовы функций программы. |
| next [n] | Выполнение очередной строки программы при пошаговой трассировке (процедуры и функции не трассируются, а выполняются за один такт). Необязательный параметр n указывает число строк программы для выполнения. По умолчанию n = 1. |
| step [n] | step [n]	Выполнение очередной строки программы (с трассировкой процедур и функций). Перед выполнением next/step программа должна быть запущена командой run. |
| set var [имя] = [выражение] | Присваивание значения переменной. |
| pytype [имя переменной] | Выводит тип переменной. |
| backtrace/bt | Распечатка содержимого стека вызовов. |
| continue | Продолжение выполнения программы после остановки. |
| quit | Выход из отладчика. |

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
```
#include <stdio.h>

int main () {
	int n, a, summ = 0;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		summ += a;
	}
	printf("%d\n", summ);
	return 0;
}
```

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя:</b> ________________
## 8. Распечатка протокола 
```
kristina@kristina-VirtualBox:~/Рабочий стол/lab10$ cc -g lab10.c
kristina@kristina-VirtualBox:~/Рабочий стол/lab10$ gdb a.out
GNU gdb (Ubuntu 12.0.90-0ubuntu1) 12.0.90
Copyright (C) 2022 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from a.out...
(gdb) help
List of classes of commands:

aliases -- User-defined aliases of other commands.
breakpoints -- Making program stop at certain points.
data -- Examining data.
files -- Specifying and examining files.
internals -- Maintenance commands.
obscure -- Obscure features.
running -- Running the program.
stack -- Examining the stack.
status -- Status inquiries.
support -- Support facilities.
text-user-interface -- TUI is the GDB text based interface.
tracepoints -- Tracing of program execution without stopping the program.
user-defined -- User-defined commands.

Type "help" followed by a class name for a list of commands in that class.
Type "help all" for the list of all commands.
Type "help" followed by command name for full documentation.
Type "apropos word" to search for commands related to "word".
Type "apropos -v word" for full documentation of commands related to "word".
Command name abbreviations are allowed if unambiguous.
(gdb) list
1	#include <stdio.h>
2	
3	int main () {
4		int n, a, summ = 0;
5		scanf("%d\n", &n);
6		for (int i = 0; i < n; i++) {
7			scanf("%d", &a);
8			summ += a;
9		}
10		printf("%d\n", summ);
(gdb) break 4
Breakpoint 1 at 0x11a4: file lab10.c, line 4.
(gdb) start
Temporary breakpoint 2 at 0x555555555195: file lab10.c, line 3.
Starting program: /home/kristina/Рабочий стол/lab10/a.out 4
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Temporary breakpoint 2, main () at lab10.c:3
3	int main () {
(gdb) set args 1 1
(gdb) show args
Argument list to give program being debugged when it is started is "1 1".
(gdb) run
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/kristina/Рабочий стол/lab10/a.out 1 1
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, main () at lab10.c:4
4		int n, a, summ = 0;
(gdb) set var n = 3
(gdb) next
5		scanf("%d\n", &n);
(gdb) next
6		for (int i = 0; i < n; i++) {
(gdb) print n
$1 = 3
(gdb) ptype n
type = int
(gdb) continue
Continuing.
0
[Inferior 1 (process 1946) exited normally]
(gdb) quit
kristina@kristina-VirtualBox:~/Рабочий стол/lab10$ gdb a.out
GNU gdb (Ubuntu 12.0.90-0ubuntu1) 12.0.90
Copyright (C) 2022 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from a.out...
(gdb) start
Temporary breakpoint 1 at 0x1195: file lab10.c, line 3.
Starting program: /home/kristina/Рабочий стол/lab10/a.out 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Temporary breakpoint 1, main () at lab10.c:3
3	int main () {
(gdb) next
4		int n, a, summ = 0;
(gdb) next
5		scanf("%d\n", &n);
(gdb) set var n = 4
(gdb) next
6		for (int i = 0; i < n; i++) {
(gdb) next
7			scanf("%d", &a);
(gdb) set var a = 5
(gdb) continue
Continuing.
20
[Inferior 1 (process 2067) exited normally]
(gdb) quit
kristina@kristina-VirtualBox:~/Рабочий стол/lab10$ exit
```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 29.10.22 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
```
-
```
## 11. Выводы
Была написана и отлажена простейшая программа на языке на Си. В результате выполнения работы, были приобретены навыки, которые будут полезны для выполнения других лабораторных работ.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> ____________________
