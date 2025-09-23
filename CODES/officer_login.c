// officer_login.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OFFICER_FILE "officers.txt"

// Dummy forward declaration
void mainMenu();
void officerDashboard();

void officerLoginPage() {
    char username[50], password[50], line[100];
    int found = 0;

    system("cls");
    printf("\t\t\t\t\t***Welcome To Officer Login Page***\n\n");
    printf("USERNAME (EX- officer1): ");
    scanf("%s", username);
    printf("PASSWORD (EX- pass123): ");
    scanf("%s", password);

    FILE *fp = fopen(OFFICER_FILE, "r");
    if (fp == NULL) {
        printf("Error opening officer file.\n");
        system("pause");
        mainMenu();
        return;
    }

    while (fgets(line, sizeof(line), fp)) {
        char fileUser[50], filePass[50];
        sscanf(line, "%[^,],%s", fileUser, filePass);
        if (strcmp(username, fileUser) == 0 && strcmp(password, filePass) == 0) {
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (found) {
        officerDashboard(); // Go to officer dashboard
    } else {
        printf("!!! Invalid USERNAME/PASSWORD !!!\n");
        system("pause");
        mainMenu();
    }
}