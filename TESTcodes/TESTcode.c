#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PATH "C:\\Users\\User\\OneDrive\\Desktop\\Educational\\Level 1 sem 1\\Fundamentals of Computer Programming\\Mini Project\\Parliment_Election_System_\\.txt files\\candidate_requests.txt"

void candidateLoginPage() {
    system("cls");
    printf("=== Candidate Login Page ===\n");
    // You can add login logic here later
}

void candidateRegistrationPage() {
    char name[100], nic[20], party[50], candidateID[20];
    char choice;

    system("cls");
    printf("=== Candidate Registration Form ===\n");
    printf("Enter Name (EX- Aloka Perera): ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline

    printf("Enter NIC (EX- 200112345678): ");
    fgets(nic, sizeof(nic), stdin);
    nic[strcspn(nic, "\n")] = '\0';

    printf("Enter Party (EX- Unity Party): ");
    fgets(party, sizeof(party), stdin);
    party[strcspn(party, "\n")] = '\0';

    printf("Enter Candidate_ID (EX- U1234c): ");
    fgets(candidateID, sizeof(candidateID), stdin);
    candidateID[strcspn(candidateID, "\n")] = '\0';

    printf("\nSubmit (S) or Back (B): ");
    scanf(" %c", &choice);
    getchar(); // clear newline from buffer

    if (choice == 'B' || choice == 'b') {
        candidateLoginPage();
        return;
    }

    FILE *fp = fopen(FILE_PATH, "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(fp, "%s|%s|%s|%s\n", name, nic, party, candidateID);
    fclose(fp);

    printf("\n✅ Registration submitted successfully!\n");
    printf("Returning to Candidate Login Page...\n");
    system("pause");
    candidateLoginPage();
}

int main() {
    candidateRegistrationPage();
    return 0;
}