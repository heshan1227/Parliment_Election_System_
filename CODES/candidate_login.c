// candidate_login.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANDIDATE_FILE "candidates.txt"

// Forward declaration of dashboard and gateway
void candidateDashboard(char candidateID[], char name[]);
void candidateGateway();

void candidateLoginPage() {
    char username[20], password[20], line[200];
    int found = 0;

    system("cls"); // Clear screen
    printf("***Welcome to Candidate Login***\n");
    printf("USERNAME (EX- U1234c): ");
    scanf("%s", username);
    printf("PASSWORD: ");
    scanf("%s", password);

    // Open candidates.txt for reading
    FILE *fp = fopen(CANDIDATE_FILE, "r");
    if (fp == NULL) {
        printf("Error opening candidates file.\n");
        system("pause");
        candidateGateway();
        return;
    }

    // Search for matching username and password
    while (fgets(line, sizeof(line), fp)) {
        char candidateID[20], name[100], nic[20], party[50], filePass[20];
        sscanf(line, "%[^|]|%[^|]|%[^|]|%[^|]|%s", candidateID, name, nic, party, filePass);

        if (strcmp(username, candidateID) == 0 && strcmp(password, filePass) == 0) {
            found = 1;
            fclose(fp);
            candidateDashboard(candidateID, name); // Go to dashboard
            return;
        }
    }

    fclose(fp);

    // If not found, show error and return to gateway
    printf("!!! Invalid USERNAME/PASSWORD !!!\n");
    system("pause");
    candidateGateway();
}