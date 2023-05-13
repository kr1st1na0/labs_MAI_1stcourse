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