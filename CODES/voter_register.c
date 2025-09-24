// voter_register.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REQUEST_FILE "voter_requests.txt"

// Dummy forward declaration
void voterGateway();

void voterRegistrationPage() {
    char status[2];
    char name[100], nic[20], password[7];
    char choice;

    system("cls"); // Clears the console screen
    printf("Voter Registration Form\n");

    printf("Name (EX- S Sandaruwan): ");
    getchar(); // clear buffer
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("NIC (EX- 200345678901): ");
    fgets(nic, sizeof(nic), stdin);
    nic[strcspn(nic, "\n")] = '\0';

    printf("PASSWORD (EX- pass123): ");
    fgets(password, sizeof(password), stdin);
    nic[strcspn(password, "\n")] = '\0';


    printf("\nSubmit (S) or Back (B): ");
    scanf(" %c", &choice);

    if (choice == 'B' || choice == 'b') {
        voterGateway();
        return;
    }

    FILE *fp = fopen(REQUEST_FILE, "a");
    if (fp == NULL) {
        printf("Error opening request file.\n");
        system("pause");
        voterGateway();
        return;
    }

    fprintf(fp, "%s|%s|%s|0\n", nic, name, password);
    fclose(fp);

    printf("\nRequest submitted successfully.\n");
    system("pause");
    voterGateway();
}