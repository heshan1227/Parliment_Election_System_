#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REQUEST_FILE "candidate_requests.txt"
#define APPROVED_FILE "candidates.txt"


void officerDashboard();
void candidateRequestsPage() {
    system("cls");

    printf("Candidate Requests\n\n");

    FILE *fp = fopen(REQUEST_FILE, "r");
    if (fp == NULL) {
        printf("No candidate requests found.\n");
        system("pause");
        officerDashboard();
        return;
    }

    char line[200];

    int index = 1;

    while (fgets(line, sizeof(line), fp)) {
        char name[100], nic[20], party[50], candidateID[20];
        sscanf(line, "%[^|]|%[^|]|%[^|]|%s", name, nic, party, candidateID);
        printf("%d. %s | %s | %s | %s\n", index++, name, nic, party, candidateID);
    }
    fclose(fp);

    printf("\nA = Approve\nR = Reject\nB = Back\n\n");
    char choice;
    printf("Enter your choice: ");
    scanf(" %c", &choice);
    getchar(); 

    if (choice == 'B' || choice == 'b') {
        officerDashboard();
        return;
    }

    fp = fopen(REQUEST_FILE, "r");
    FILE *temp = fopen("temp.txt", "w");
    FILE *approved = fopen(APPROVED_FILE, "a");

    int processed = 0;
    while (fgets(line, sizeof(line), fp)) {
        if (processed == 0) {
            char name[100], nic[20], party[50], candidateID[20];
            sscanf(line, "%[^|]|%[^|]|%[^|]|%s", name, nic, party, candidateID);

            if (choice == 'A' || choice == 'a') {
                fprintf(approved, "%s|%s|%s|%s|pass123\n", candidateID, name, nic, party); 
                printf("Approved: %s\n", name);
            } else if (choice == 'R' || choice == 'r') {
                printf("Rejected: %s\n", name);
            }
            processed = 1;
        } else {
            fputs(line, temp);
        }
    }

    fclose(fp);
    fclose(temp);
    fclose(approved);

    remove(REQUEST_FILE);
    rename("temp.txt", REQUEST_FILE);

    system("pause");
    candidateRequestsPage(); 
}