// candidate_register.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REQUEST_FILE "candidate_requests.txt"

// Dummy forward declaration
void candidateGateway();

void candidateRegistrationPage() {
    char name[100], nic[20], party[50], candidateID[20];
    char choice;

    system("cls"); // Clears the console screen
    printf("Candidate Registration Form\n\n");

    printf("Name (EX- Aloka Perera): ");
    getchar(); // clear buffer before fgets
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("NIC (EX- 200112345678): ");
    fgets(nic, sizeof(nic), stdin);
    nic[strcspn(nic, "\n")] = '\0';

    printf("Party (EX- Unity Party): ");
    fgets(party, sizeof(party), stdin);
    party[strcspn(party, "\n")] = '\0';

    printf("Candidate_ID (EX- U1234c): ");
    fgets(candidateID, sizeof(candidateID), stdin);
    candidateID[strcspn(candidateID, "\n")] = '\0';

    printf("\n\n\nSubmit (S) or Back (B): ");
    scanf(" %c", &choice);

    if (choice == 'B' || choice == 'b') {
        candidateGateway();
        return;
    }

    FILE *fp = fopen(REQUEST_FILE, "a");
    if (fp == NULL) {
        printf("Error opening request file.\n");
        system("pause");
        candidateGateway();
        return;
    }

    fprintf(fp, "%s|%s|%s|%s\n", name, nic, party, candidateID);
    fclose(fp);

    printf("\n\nRequest submitted successfully.\n");
    system("pause");
    candidateGateway();
}