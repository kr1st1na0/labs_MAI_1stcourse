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

/*
// Without bin_file.bin
void upgrade(line * l, int size) {
    reference ref;
    ref.cpu_freq = 2200;
    ref.hdd_size = 4096;
    ref.gpu_memory = 6;
    bool f = true;
    for (int i = 0; i < size; i++) {
        if (l[i].spec.cpu_freq <= ref.cpu_freq || l[i].spec.hdd_size <= ref.hdd_size || l[i].spec.gpu_memory <= ref.gpu_memory) {
            if (f) {
                printf("---------\nNeed upgrade:\n");
                printf("Owner\tCpu\tHdd\tGpu\tOS\n");
                f = false;
            }
            printf("%s\t%d\t%d\t%d\t%s\n", l[i].owner, l[i].spec.cpu_freq, l[i].spec.hdd_size, 
            l[i].spec.gpu_memory, l[i].spec.os_type);
        }
    }
    if (f) {
        printf("---------\nNobody needs upgrade\n");
    }
}
*/
void tablePrint(line * l, int size) {
    printf("№  Owner\tCpu\tHdd\tGpu\tOS\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s\t%d\t%d\t%d\t%s\n", i + 1, l[i].owner, l[i].spec.cpu_freq, l[i].spec.hdd_size, 
        l[i].spec.gpu_memory, l[i].spec.os_type);
    }
}

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
    tablePrint(l, size);
    // upgrade(l, size);
    fclose(out);
    fclose(in);
    return 0;
}