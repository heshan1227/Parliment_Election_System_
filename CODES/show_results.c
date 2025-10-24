// show_results.c
#include <stdio.h>
#include <stdlib.h>

#define RESULT_FILE "result.txt"

void showResults() {
    char line[200];

    system("cls");
    FILE *fp = fopen(RESULT_FILE, "r");

    if (fp == NULL) {
        printf("Parliament Election 2050 – Results —Not ready yet—\n");
    } else {
        printf("Parliament Election 2050 – Results\n\n\n");
        while (fgets(line, sizeof(line), fp)) {
            printf("%s", line);
        }
        fclose(fp);
    }

    printf("\n");
    system("pause");
}