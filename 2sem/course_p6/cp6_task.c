// Отпечатать список студентов, компьютеры которых нуждаются в апгрейде.
// gcc cp6_task.c && ./a.out bin_file.bin
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

int main(int argc, char *argv[]) {
    FILE *f;
    line l[MAX_TEXT_SIZE];
    int size = 0;
    reference ref;
    ref.cpu_freq = 2200;
    ref.hdd_size = 4096;
    ref.gpu_memory = 6;
    bool flag = true;
    if ((f = fopen(argv[1], "r")) == NULL) {
        printf("Can not open file\n");
        return 2;
    }
    while (fread(&l, sizeof(l), 1, f)) {
        int spec [] = {l[size].spec.cpu_freq, l[size].spec.hdd_size, l[size].spec.gpu_memory};
        if (spec[0] <= ref.cpu_freq || spec[1] <= ref.hdd_size || spec[2] <= ref.gpu_memory) {
            if (flag) {
                printf("Need upgrade:\n");
                printf("Owner\tCpu\tHdd\tGpu\tOS\n");
                flag = false;
            }
            printf("%s\t%d\t%d\t%d\t%s\n", l[size].owner, l[size].spec.cpu_freq, l[size].spec.hdd_size, 
            l[size].spec.gpu_memory, l[size].spec.os_type);
        }
        ++size;
    }
    if (flag) {
        printf("Nobody needs upgrade\n");
    }
    fclose(f);
    return 0;
}