# Отчёт по курсовой работе №6 по курсу “Языки и методы программирования”

<b>Студент группы:</b> <ins>М80-108Б-22 Былькова Кристина Алексеевна, № по списку 2</ins>

<b>Контакты e-mail:</b> <ins>kristina.bilckova@yandex.ru</ins>

<b>Работа выполнена:</b> «13» <ins>мая</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>5</ins>

<b>Отчет сдан</b> «13» <ins>мая</ins> <ins>2023</ins> г., <b>итоговая оценка</b>5<ins>

<b>Подпись преподавателя:</b> ___________


## 1. Тема
Обработка последовательной файловой структуры на языке Си

## 2. Цель работы
Разработать последовательную структуру данных для представления простейшей базы данных на файлах в СП Си в соответствии с заданным вариантом. Составить программу генерации внешнего нетекстового файла заданной структуры, содержащего представительный набор записей (не менее 20). Распечатать содержимое сгенерированного файла в виде таблицы и выполнить над ним заданное действие.

## 3. Задание (вариант № 4)
Отпечатать список студентов, компьютеры которых нуждаются в апгрейде.

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

<b>Утилиты операционной системы:</b> -

<b>Прикладные системы и программы:</b> -

</b>Местонахождение и имена файлов программ и данных на домашнем компьютере:</b> /home/kristina

## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)

Курсовой проект состоит из двух файлов: cp6_in-out.c (считывание текстового файла и запись считанных данных в бинарный файл) и cp6_task.c (выполнение задания по варианту).


## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию].

<b>cp6_in-out.c</b>

``` :src/cp6_in-out.c
// Считывание текстового файла и запись считанных данных в бинарный файл.
// gcc cp6_in-out.c && ./a.out test.txt bin_file.bin
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_SIZE 100
#define MAX_TEXT_SIZE 100

typedef struct {
    int cpu_freq;
    int hdd_size;
    int gpu_memory;
    char os_type[3];
} computer;

typedef struct {
    computer spec;
    char owner[MAX_STRING_SIZE];    
} line;

typedef struct {
    int cpu_freq;
    int hdd_size;
    int gpu_memory;
} reference;

int main(int argc, char * argv[]) {
    line l[MAX_TEXT_SIZE];
    int size = 0;
    FILE *in = fopen(argv[1], "r"); // txt
    FILE *out = fopen(argv[2], "w"); // bin
    if (!(out&&in)){
        printf("Can't open file");
        return 2;
    }
    while (!feof(in)) {
        fscanf(in, "%s %d %d %d %s\n", l[size].owner, &l[size].spec.cpu_freq, &l[size].spec.hdd_size, 
        &l[size].spec.gpu_memory, l[size].spec.os_type);
        fwrite(&l, sizeof(l), 1, out);
        ++size;
    }
    fclose(out);
    fclose(in);
    return 0;
}
```

<b>cp6_task.c</b>

``` :src/cp6_task.c
// Отпечатать список студентов, компьютеры которых нуждаются в апгрейде.
// gcc cp6_task.c && ./a.out -f/1/2/3 bin_file.bin
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_SIZE 100
#define MAX_TEXT_SIZE 100

typedef struct {
    int cpu_freq;
    int hdd_size;
    int gpu_memory;
    char os_type[3];
} computer;

typedef struct {
    computer spec;
    char owner[MAX_STRING_SIZE];    
} line;

typedef struct {
    int cpu_freq;
    int hdd_size;
    int gpu_memory;
} reference;

void tablePrint(FILE *f) {
    line l[MAX_TEXT_SIZE];
    int size = 0;
    printf("№  Owner\tCpu\tHdd\tGpu\tOS\n");
    while (fread(&l, sizeof(l), 1, f)) {
        printf("%d. %s\t%d\t%d\t%d\t%s\n", size + 1, l[size].owner, l[size].spec.cpu_freq, l[size].spec.hdd_size, 
        l[size].spec.gpu_memory, l[size].spec.os_type);
        ++size;
    }
}

void upgrade(line * l, int p, int size, int spec[]) {
    reference ref;
    ref.cpu_freq = 2200;
    ref.hdd_size = 4096;
    ref.gpu_memory = 6;
    if (p == 1) {
        if (spec[0] <= ref.cpu_freq || spec[1] <= ref.hdd_size || spec[2] <= ref.gpu_memory) {
            printf("%s\t%d\t%d\t%d\t%s\n", l[size].owner, l[size].spec.cpu_freq, l[size].spec.hdd_size, 
            l[size].spec.gpu_memory, l[size].spec.os_type);
        }
    }
    else if (p == 2) {
        if ((spec[0] <= ref.cpu_freq && spec[1] <= ref.hdd_size || spec[2] <= ref.gpu_memory) || 
        (spec[0] <= ref.cpu_freq || spec[1] <= ref.hdd_size || spec[2] <= ref.gpu_memory) ||
        (spec[0] <= ref.cpu_freq && spec[2] <= ref.hdd_size || spec[1] <= ref.gpu_memory)) {
            printf("%s\t%d\t%d\t%d\t%s\n", l[size].owner, l[size].spec.cpu_freq, l[size].spec.hdd_size, 
            l[size].spec.gpu_memory, l[size].spec.os_type);
        }
    }
    else if (p == 3) {
        if (spec[0] <= ref.cpu_freq && spec[1] <= ref.hdd_size && spec[2] <= ref.gpu_memory) {
            printf("%s\t%d\t%d\t%d\t%s\n", l[size].owner, l[size].spec.cpu_freq, l[size].spec.hdd_size, 
            l[size].spec.gpu_memory, l[size].spec.os_type);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *f;
    line l[MAX_TEXT_SIZE];
    int size = 0;
    if (argc == 1 || argc == 2) {
        printf("Too few arguments\n");
        return 1;
    }
    if (argc > 3) {
        printf("Too many arguments\n");
    }
    if (!strcmp(argv[1], "-f")) {
        f = fopen(argv[2], "r");
        tablePrint(f);
    }
    int p = atoi(argv[1]);
    if (f = fopen(argv[2], "r"), f == NULL) {
        printf("Can not open file\n");
        return 2;
    }
    if (strcmp(argv[1], "-f")) {
        printf("Need upgrade:\n");
        printf("Owner\tCpu\tHdd\tGpu\tOS\n");
    }
    while (fread(&l, sizeof(l), 1, f)) {
        int spec [] = {l[size].spec.cpu_freq, l[size].spec.hdd_size, l[size].spec.gpu_memory};
        upgrade(l, p, size, spec);
        ++size;
    }
    fclose(f);
    return 0;
}
```

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя:</b> _____________________

## 8. Распечатка протокола 

```
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp6$ cat test1.txt
Smirnov 2000 6144 8 win
Petrov 3000 4096 12 mac
Ivanov 2500 1024 6 mac
Popov 3200 3072 16 lin
Kozlov 3500 8192 16 win
Pavlov 2700 5120 8 win
Bogdanov 3300 6144 12 lin
Egorov 2200 1000 4 mac
Semenov 2800 5120 16 win
Kotov 2000 7168 6 mac
Fomin 3000 7168 8 lin
Mironov 2600 7168 12 win
Blinov 2500 5120 8 mac
Borisov 3200 6144 16 mac
Romanov 2100 5120 6 win
Sorokin 2500 1024 6 lin
Petrov 3700 7168 12 mac
Kotov 2800 1024 8 lin
Karpov 3100 8192 16 win
Ershov 3600 5120 8 win
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp6$ gcc cp6_in-out.c && ./a.out test1.txt bin_file.bin
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp6$ gcc cp6_task.c && ./a.out -f bin_f
ile.bin
№  Owner        Cpu     Hdd     Gpu     OS
1. Smirnov      2000    6144    8       win
2. Petrov       3000    4096    12      mac
3. Ivanov       2500    1024    6       mac
4. Popov        3200    3072    16      lin
5. Kozlov       3500    8192    16      win
6. Pavlov       2700    5120    8       win
7. Bogdanov     3300    6144    12      lin
8. Egorov       2200    1000    4       mac
9. Semenov      2800    5120    16      win
10. Kotov       2000    7168    6       mac
11. Fomin       3000    7168    8       lin
12. Mironov     2600    7168    12      win
13. Blinov      2500    5120    8       mac
14. Borisov     3200    6144    16      mac
15. Romanov     2100    5120    6       win
16. Sorokin     2500    1024    6       lin
17. Petrov      3700    7168    12      mac
18. Kotov       2800    1024    8       lin
19. Karpov      3100    8192    16      win
20. Ershov      3600    5120    8       win
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp6$ gcc cp6_task.c && ./a.out 1 bin_fi
le.bin
Need upgrade:
Owner   Cpu     Hdd     Gpu     OS
Smirnov 2000    6144    8       win
Petrov  3000    4096    12      mac
Ivanov  2500    1024    6       mac
Popov   3200    3072    16      lin
Egorov  2200    1000    4       mac
Kotov   2000    7168    6       mac
Romanov 2100    5120    6       win
Sorokin 2500    1024    6       lin
Kotov   2800    1024    8       lin
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp6$ gcc cp6_task.c && ./a.out 2 bin_fi
le.bin
Need upgrade:
Owner   Cpu     Hdd     Gpu     OS
Smirnov 2000    6144    8       win
Petrov  3000    4096    12      mac
Ivanov  2500    1024    6       mac
Popov   3200    3072    16      lin
Egorov  2200    1000    4       mac
Kotov   2000    7168    6       mac
Romanov 2100    5120    6       win
Sorokin 2500    1024    6       lin
Kotov   2800    1024    8       lin
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp6$ gcc cp6_task.c && ./a.out 3 bin_fi
le.bin
Need upgrade:
Owner   Cpu     Hdd     Gpu     OS
Egorov  2200    1000    4       mac
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp6$ cat test2.txt
Smirnov 2300 6144 8 win
Petrov 3000 7168 12 mac
Ivanov 2500 5120 8 mac
Popov 3200 5120 16 lin
Kozlov 3500 8192 16 win
Pavlov 2700 5120 8 win
Bogdanov 3300 6144 12 lin
Egorov 2400 8192 8 mac
Semenov 2800 5120 16 win
Kotov 2300 7168 12 mac
Fomin 3000 7168 8 lin
Mironov 2600 7168 12 win
Blinov 2500 5120 8 mac
Borisov 3200 6144 16 mac
Romanov 2400 5120 12 win
Sorokin 2500 8192 8 lin
Petrov 3700 7168 12 mac
Kotov 2800 6144 8 lin
Karpov 3100 8192 16 win
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp6$ gcc cp6_in-out.c && ./a.out test2.
txt bin_file.bin
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp6$ gcc cp6_task.c && ./a.out -f bin_f
ile.bin
№  Owner        Cpu     Hdd     Gpu     OS
1. Smirnov      2300    6144    8       win
2. Petrov       3000    7168    12      mac
3. Ivanov       2500    5120    8       mac
4. Popov        3200    5120    16      lin
5. Kozlov       3500    8192    16      win
6. Pavlov       2700    5120    8       win
7. Bogdanov     3300    6144    12      lin
8. Egorov       2400    8192    8       mac
9. Semenov      2800    5120    16      win
10. Kotov       2300    7168    12      mac
11. Fomin       3000    7168    8       lin
12. Mironov     2600    7168    12      win
13. Blinov      2500    5120    8       mac
14. Borisov     3200    6144    16      mac
15. Romanov     2400    5120    12      win
16. Sorokin     2500    8192    8       lin
17. Petrov      3700    7168    12      mac
18. Kotov       2800    6144    8       lin
19. Karpov      3100    8192    16      win
20. Ershov      3600    5120    8       win
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp6$ gcc cp6_task.c && ./a.out 1 bin_fi
le.bin
Need upgrade:
Owner   Cpu     Hdd     Gpu     OS
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp6$ gcc cp6_task.c && ./a.out 2 bin_fi
le.bin
Need upgrade:
Owner   Cpu     Hdd     Gpu     OS
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp6$ gcc cp6_task.c && ./a.out 3 bin_file.bin
Need upgrade:
Owner   Cpu     Hdd     Gpu     OS
```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 13.05.23 | 13:00 | Выполнение лабораторной работы | - | - |

## 10. Замечания автора по существу работы

<b>div3</b>

- [Задача во время контеста](https://codeforces.com/contest/1800/submission/195661017)
- [Дорешка](https://codeforces.com/contest/1800/submission/197397209)
- [Дорешка](https://codeforces.com/contest/1800/submission/205359462)


## 11. Выводы
Была разработана последовательная структура данных для представления простейшей базы данных на файлах в СП Си в соответствии с заданным вариантом. Была составлена программа генерации внешнего нетекстового файла заданной структуры и ввыполнения определенного действия в соответствие с вариантом.  Были приобретены навыки, которые будут полезны для выполнения других лабораторных работ и курсовых проектов.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> _________________


