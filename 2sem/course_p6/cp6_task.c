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