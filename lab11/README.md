# Отчёт по лабораторной работе №11 по курсу "Фундаментальная информатика"

<b>Студент группы:</b> <ins>М80-108Б-22 Былькова Кристина Алексеевна, № по списку 2</ins> 

<b>Контакты e-mail:</b> <ins>kristina.bilckova@yandex.ru</ins>

<b>Работа выполнена:</b> «29» <ins>октября</ins> <ins>2022</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>5 (отлично)</ins>

<b>Отчет сдан</b> «29» <ins>октября</ins> <ins>2022</ins> г., <b>итоговая оценка</b> <ins>5 (отлично)</ins>

<b>Подпись преподавателя:</b> ________________

## 1. Тема
Обработка последовательности литер входного текстового файла. Простейшие приёмы лексического анализа. Диаграммы состояний переходов.
## 2. Цель работы
Составить программу на языке Си, выполняющую анализ и обработку вводимого текста.
## 3. Задание (вариант № 2)
Подсчитать число слов в многострочных комментариях (/* и */) в программе на Си.
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

<b>Прикладные системы и программы:</b> gcc

<b>Местонахождение и имена файлов программ и данных на домашнем компьютере:</b> /home/kristina

## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)
```
#include <stdio.>

int main() {
/* this is comment **/
	int n = 10;
	return 0;
	/**comment 2 */
}
```

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
```
#include <stdio.h>

typedef enum {
  OUTSIDE,
  FIRST_SOLIDUS,
  FIRST_ASTERISK,
  WORD,
  SEPARATOR,
  LAST_ASTERISK,
  LAST_SOLIDUS,
} State;

int number();

int main(void) {
  printf("Number of words in a multiline comment: %d\n", number());
  return 0;
}

int number() {
  int result = 0;
  State state = OUTSIDE;
  for (char ch = getchar(); ch != EOF; ch = getchar()) {
    switch (state) {
      case OUTSIDE:
      if (ch == '/')
        state = FIRST_SOLIDUS;
        break;
    case FIRST_SOLIDUS:
      if (ch == '*')
        state = FIRST_ASTERISK;
        break;
    case FIRST_ASTERISK:
      if (ch == '*')
        state = SEPARATOR;
      else if (ch == '/')
        state = OUTSIDE;
      else if (ch != ' ' && ch != '\n')
        state = WORD;
        break;
    case SEPARATOR:
      if (ch == '/') {
        state = OUTSIDE;
        continue;
      }
      if (ch == '*') {
        state = LAST_ASTERISK;
        continue;
      }
      if (ch == ' ' || ch == '\n') {
        ++result;
        state = FIRST_ASTERISK;
        continue;
      }
        else {
          state =  WORD;
          continue;
            }
      case WORD:
        if (ch == '*')
          state = LAST_ASTERISK;
        else if (ch == ' ' || ch == '\n') {
          ++result;
          state = FIRST_ASTERISK;
        }
      case LAST_ASTERISK:
        if (ch == '/') {
          ++result;
          state = OUTSIDE;
          continue;
        }
        if (ch == '*') {
          state = LAST_SOLIDUS;
          continue;
        }
        else {
          state = WORD;
          continue;
        }
      case LAST_SOLIDUS:
        if (ch != '/') {
          continue;
        }
        else {
          ++result;
          state = OUTSIDE;
          continue;
        }
      }
    }
  return result;
}
```

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя:</b> ________________
## 8. Распечатка протокола 
```
kristina@kristina-VirtualBox:~/Рабочий стол/lab11$ cc -g lab11.c
kristina@kristina-VirtualBox:~/Рабочий стол/lab11$ cat main.c
#include <stdio.>

int main() {
/* this is comment **/
  int n = 10;
  return 0;
  /**comment 2 */
}
kristina@kristina-VirtualBox:~/Рабочий стол/lab11$ ./a.out < main.c
Number of words in a multiline comment: 6
kristina@kristina-VirtualBox:~/Рабочий стол/lab11$ exit
```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 29.10.22 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
Защита была проведена без замечаний.
## 11. Выводы
Была написана программа на языке на Си, выполняющая анализ и обработку текста. В результате выполнения работы, были приобретены навыки для работы с текстовыми входными данными и машинами состояний.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> ____________________
