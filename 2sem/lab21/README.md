# Отчёт по лабораторной работе №21 по курсу “Языки и методы программирования”

<b>Студент группы:</b> <ins>М80-108Б-22 Былькова Кристина Алексеевна, № по списку 2</ins>

<b>Контакты e-mail:</b> <ins>kristina.bilckova@yandex.ru</ins>

<b>Работа выполнена:</b> «25» <ins>марта</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «25» <ins>марта</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ___________


## 1. Тема
Программирование на интерпретируемых командных языках
## 2. Цель работы
Составить программу выполнения заданных действий над файлами на одном из интерпретируемых командных языков OC UNIX (Shell, Cshell, Bash, ...), согласованном с преподавателем - Bash и Python.
## 3. Задание (вариант № 2)
Объединение в один файл всех файлов с указанным суффиксом, имеющих размер меньше заданного.
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

<b>Утилиты операционной системы:</b> echo, read, find, stat, cat, rm

<b>Прикладные системы и программы:</b> -

</b>Местонахождение и имена файлов программ и данных на домашнем компьютере:</b> /home/kristina

## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)

| Команда |  Описание |
| ------ | ------ |
| echo | выводим сообщение на экран |
| read | считываем введённую информацию и записываем |
| echo -n | создаем пустой файл или очищаем существующий |
| find | находим файлы в текущей директории, подходящие под заданные параметры |
| stat -c %s | выводим размер файла в байтах |
| cat | выводим содержимое файла на экран |
| rm | удаляем файл |


## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию].

1. Запрашиваем у пользователя суффикс
2. Запрашиваем у пользователя размер
3. Если пользователь не ввёл размер и суффикс файла, то задаём "txt" и "100"
4. Создаём пустой файл, в который будем записывать подходящие файлы
5. В текущей директории ищем файлы с заданным суффиксом
6. Записываем размер каждого файла в file_size
7. Сравниваем размер файла с заданным размером
8. Если файл подходит по критериям, то копируем его содержимое в файл-ответ
9. Выводим содержимое файла-ответа
10. Удаляем файл-ответ

<b>Bash:</b>
```
#!/bin/bash

echo "Enter the suffix of files or press "?" if you don't want to enter the value:"
read suffix
suffix=$suffix

echo "Enter the size in bytes or press "?" if you don't want to enter the value:"
read size
size=$size

if [ "$suffix" == "?" ]; then
  suffix="txt"
fi

if [ "$size" == "?" ]; then
  size=100
fi

echo -n > /home/kristina/lab21/answer

for i in $(find ./ -name \*."$suffix" -type f -print)
do
  file_size=$(stat -c %s "$i")
  if [ "$file_size" -le "$size" ]; then
    cat "$i"  >> /home/kristina/lab21/answer
  fi
done

cat /home/kristina/lab21/answer

rm /home/kristina/lab21/answer
```

<b>Python:</b>
```
#!/usr/bin/env python

import os
from os.path import getsize
from os.path import join

print("Enter the suffix of files or press '?' if you don't want to enter the value:")
suffix = input()

print("Enter the size in bytes or press '?' if you don't want to enter the value:")
size = input()

if suffix == "?":
    suffix = "txt"

if size == "?":
    size = int(100)
else:
    size = int(size)

directory = "lab21"

for (root, dirs, files) in os.walk(directory):
    for file in files:
        in_name = join(root, file)
        cur_size = getsize(in_name)
        if file.endswith(suffix) and cur_size <= size:
            with open(in_name, "r") as input:
                with open("ans", "a") as output:
                    for line in input:
                        output.write(line)

with open("ans", "r") as print_content:
    for line in print_content:
        print(line, end = '')

os.remove("ans")
```

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя:</b> _____________________

## 8. Распечатка протокола 

<b>Bash:</b>
```
kristina@kristina-VirtualBox:~/lab21$ ls -l
итого 36
-rw-rw-r-- 1 kristina kristina    35 мар 18 12:31 1.txt
-rw-rw-r-- 1 kristina kristina    94 мар 18 03:45 2.txt
-rw-rw-r-- 1 kristina kristina  3278 мар 18 03:46 3.txt
-rw-rw-r-- 1 kristina kristina    64 мар 18 02:06 4.c
-rwxrwxr-x 1 kristina kristina 15960 мар 18 02:06 a.out
-rwxrwxr-x 1 kristina kristina   608 мар 19 12:56 lab21.sh
kristina@kristina-VirtualBox:~/lab21$ cat 1.txt
sbkdvjcndd
fbijngfbn
vnfiujfnfjnjf
kristina@kristina-VirtualBox:~/lab21$ cat 2.txt
4634783597598
39847427497498
244842082409
35yhgf9385yhg3oir5h
g359uyh39ou8h8ighu
358ryhg8392g
kristina@kristina-VirtualBox:~/lab21$ cat 3.txt
hbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgck
hbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgck
hbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgck
hbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgck
hbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgck
hbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgck
hbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgck
hbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgck
hbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgck
hbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgck
kristina@kristina-VirtualBox:~/lab21$ cat 4.c
#include <stdio.h>

int main() {
  printf("Hello, world!\n");
}
kristina@kristina-VirtualBox:~/lab21$ ./lab21.sh
Enter the suffix of files or press ? if you don't want to enter the value:
?
Enter the size in bytes or press ? if you don't want to enter the value:
?
sbkdvjcndd
fbijngfbn
vnfiujfnfjnjf
4634783597598
39847427497498
244842082409
35yhgf9385yhg3oir5h
g359uyh39ou8h8ighu
358ryhg8392g
kristina@kristina-VirtualBox:~/lab21$ ./lab21.sh
Enter the suffix of files or press ? if you don't want to enter the value:
txt
Enter the size in bytes or press ? if you don't want to enter the value:
60
sbkdvjcndd
fbijngfbn
vnfiujfnfjnjf
kristina@kristina-VirtualBox:~/lab21$ ./lab21.sh
Enter the suffix of files or press ? if you don't want to enter the value:
c
Enter the size in bytes or press ? if you don't want to enter the value:
100
#include <stdio.h>

int main() {
  printf("Hello, world!\n");
}

```

<b>Python:</b>
```
kristina@kristina-VirtualBox:~/lab21$ ls -l
итого 36
-rw-rw-r-- 1 kristina kristina    35 мар 18 12:31 1.txt
-rw-rw-r-- 1 kristina kristina    94 мар 18 03:45 2.txt
-rw-rw-r-- 1 kristina kristina  3278 мар 18 03:46 3.txt
-rw-rw-r-- 1 kristina kristina    64 мар 18 02:06 4.c
-rwxrwxr-x 1 kristina kristina 15960 мар 18 02:06 a.out
-rwxrwxr-x 1 kristina kristina   608 мар 20 13:25 lab21.sh
kristina@kristina-VirtualBox:~/lab21$ cat 1.txt
sbkdvjcndd
fbijngfbn
vnfiujfnfjnjf
kristina@kristina-VirtualBox:~/lab21$ cat 2.txt
4634783597598
39847427497498
244842082409
35yhgf9385yhg3oir5h
g359uyh39ou8h8ighu
358ryhg8392g
kristina@kristina-VirtualBox:~/lab21$ cat 3.txt
hbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgck
hbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgck
hbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgck
hbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgck
hbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgck
hbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgck
hbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgck
hbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgck
hbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgck
hbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgckhbkjugbuigbyivfugclghcggfcgfhckgtfcgck
kristina@kristina-VirtualBox:~/lab21$ cat 4.c
#include <stdio.h>

int main() {
  printf("Hello, world!\n");
}
kristina@kristina-VirtualBox:~/lab21$ cd ..
kristina@kristina-VirtualBox:~$ python3 lab21.py
Enter the suffix of files or press '?' if you don't want to enter the value:
?
Enter the size in bytes or press '?' if you don't want to enter the value:
?
sbkdvjcndd
fbijngfbn
vnfiujfnfjnjf
4634783597598
39847427497498
244842082409
35yhgf9385yhg3oir5h
g359uyh39ou8h8ighu
358ryhg8392g
kristina@kristina-VirtualBox:~$ python3 lab21.py
Enter the suffix of files or press '?' if you don't want to enter the value:
txt
Enter the size in bytes or press '?' if you don't want to enter the value:
60
sbkdvjcndd
fbijngfbn
vnfiujfnfjnjf
kristina@kristina-VirtualBox:~$ python3 lab21.py
Enter the suffix of files or press '?' if you don't want to enter the value:
c
Enter the size in bytes or press '?' if you don't want to enter the value:
100
#include <stdio.h>

int main() {
  printf("Hello, world!\n");
}

```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 25.03.23 | 13:00 | Выполнение лабораторной работы | - | - |

## 10. Замечания автора по существу работы

<b>Защита: div2</b>

- [Задача во время контеста](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427390/submission/197654796)
- [Задача во время контеста](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427390/submission/197658205)
- [Дорешка](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427390/submission/197834908)

## 11. Выводы
Было выяснено, что в OC UNIX выполнять различные действия над файлами можно не только в командной строке, но и с помощью программ, написанных на интерпретируемом языке Bash. Была составлена программа, которая выполняет заданные над файлами действия. Также была составлена аналогичная программа на Python. В результате выполнения работы, были приобретены навыки, которые будут полезны для выполнения других лабораторных работ и курсовых проектов.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> _________________


