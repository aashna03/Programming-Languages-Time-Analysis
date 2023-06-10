
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

#include <stdio.h>

int main() {
    FILE *file;
    FILE *fptr;

    char ch;
    clock_t start, end;
    double cpu_time_used;
    char snum[12];
    char string_2[12] = ".txt";
    fptr = fopen("outputc.csv", "w+");

    for(int i = 200; i <= 1000; i+=200){
        int num = i;
        char file_name[12] = "_";
        sprintf(snum, "%d", num);
        strcat(file_name,snum);
        strcat(file_name,string_2);
        // printf( "%s", snum);
        file = fopen(file_name, "r+");
        start = clock();
        while ((ch = fgetc(file)) != EOF) {
                fseek(file, -1, SEEK_CUR);
                char c = toupper(ch);
                fputc(c, file);
                fseek(file, 0, SEEK_CUR);
        }
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        fprintf(fptr, "%f\n",cpu_time_used );
        printf("CPU Time Used: %f seconds\n", cpu_time_used);
    }
        fclose(file);

    return 0;
}