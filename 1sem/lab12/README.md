# Отчёт по лабораторной работе №12 по курсу "Фундаментальная информатика"

<b>Студент группы:</b> <ins>М80-108Б-22 Былькова Кристина Алексеевна, № по списку 2</ins> 

<b>Контакты e-mail:</b> <ins>kristina.bilckova@yandex.ru</ins>

<b>Работа выполнена:</b> «29» <ins>октября</ins> <ins>2022</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>5 (отлично)</ins>

<b>Отчет сдан</b> «29» <ins>октября</ins> <ins>2022</ins> г., <b>итоговая оценка</b> <ins>5 (отлично)</ins>

<b>Подпись преподавателя:</b> ________________

## 1. Тема
Техника работы с целыми числами. Системы счисления.
## 2. Цель работы
Составить программу на языке Си в целом типе данных, которая для любых допустимых и корректно записанных чисел этого типа в десятичном изображении, поступающих на стандартный ввод программы, выполняет указанное вариантом действие над их значениями.
## 3. Задание (вариант № 2)
Выбрать тройки идущих подряд цифр числа, сумма которых максимальная.
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
1. Ввод числа; 
2. Проверка;
3. Определение его длины;
4. Запись цифр в массив;
5. Реверс массива;
6. Определение максимальной суммы из всех троек;
7. Вывод всех троек с максимальной суммой;

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
``` :src/lab12-1.c
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, len;
	scanf("%d", &n);
	if (n > -100 && n < 100) {
		printf("This number is not correct.\n");
	}
	else {
		if (n < 0) {
			n = abs(n);
		}
		int n1 = n;
		while (n1 > 0) {
			len++;
			n1 /= 10;
		}
		int mas[len];
		int k = 0;
		while (n > 0) {
			mas[k] = n%10;
			n /= 10;
			k += 1;
		}
		for (int i = 0; i < len/2; i++) {
			int temp = mas[i];
			mas[i] = mas[len-i-1];
			mas[len-i-1] = temp;
		}
		int max = -1;
		for (int i = 0; i <= len - 3; i++) {
			int sum = mas[i] + mas[i+1] + mas[i+2];
			if (sum > max) {
				max = sum;
			}
		}
		printf("Max sum: %d\n", max);
		for (int i = 0; i <= len - 3; i++) {
			int sum = mas[i] + mas[i+1] + mas[i+2];
			if (sum == max) {
				printf("Numbers: %d %d %d\n", mas[i], mas[i+1], mas[i+2]);
			}
		}
	}
}
```

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя:</b> ________________
## 8. Распечатка протокола 
```
kristina@kristina-VirtualBox:~/Рабочий стол/lab12$ cc -g lab12.c
kristina@kristina-VirtualBox:~/Рабочий стол/lab12$ ./a.out
10289
Max sum: 19
Numbers: 2 8 9
kristina@kristina-VirtualBox:~/Рабочий стол/lab12$ ./a.out
28082
Max sum: 16
Numbers: 8 0 8
kristina@kristina-VirtualBox:~/Рабочий стол/lab12$ ./a.out
31031
Max sum: 4
Numbers: 3 1 0
Numbers: 1 0 3
Numbers: 0 3 1
kristina@kristina-VirtualBox:~/Рабочий стол/lab12$ ./a.out
10
This number is not correct.
kristina@kristina-VirtualBox:~/Рабочий стол/lab12$ ./a.out
-905
Max sum: 14
Numbers: 9 0 5
kristina@kristina-VirtualBox:~/Рабочий стол/lab12$ ./a.out
-17189
Max sum: 18
Numbers: 1 8 9
kristina@kristina-VirtualBox:~/Рабочий стол/lab12$ exit
```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 29.10.22 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
``` :src/lab12.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define THREE (3)

typedef struct {
    int array[THREE];
    int idx;
} CyclicArray;

int sum(int array[THREE]) {
    int s = 0;
    for (int i = 0; i < THREE; i++) {
        s += array[i];
    }
    return s;
}

void func(int maxArray[THREE]);

int main() {
    int maxArray[THREE] = { 0, 0, 0 };
    func(maxArray);
    printf("MaxSum = %d\n", sum(maxArray));
    printf("Numbers: ");
    for (int i = 0; i < THREE; i++) {
        printf("%d ", maxArray[i]);
    }
    printf("\n");
    return 0;
}

int update(CyclicArray *cyclic, int digit) {
    int result = cyclic->array[cyclic->idx];
    cyclic->array[cyclic->idx++] = digit;
    cyclic->idx %= THREE;
    return result;
}

void func(int maxArray[THREE]) {
    int iter = 0;
    memset(maxArray, 0, THREE * sizeof maxArray[0]);
    int currentSum = 0, maxSum = 0;
    CyclicArray  cyclic = { { 0, 0, 0}, 0 };
    for (int ch = getchar(); ch != EOF; ch = getchar(), ++iter) {
        int digit = ch - '0';
        currentSum -= update(&cyclic, digit);
        currentSum += digit;
        if (currentSum > maxSum) {
            memcpy(maxArray, cyclic.array, sizeof cyclic.array);
            maxSum = currentSum;
        }
    }
}

```
## 11. Выводы

Была написана программа на языке на Си, выполняющая указанное вариантом действие над значениями в целом типе данных. В результате выполнения работы, были приобретены навыки для работы с числами в целом типе данных.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> ____________________
