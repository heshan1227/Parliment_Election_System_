// candidate_requests.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void candidateRequestsPage();
// Dummy forward declaration
void officerDashboard(){
    int choice;

    system("cls");
    printf("Hello! Mr./Mrs. officer1\n\n");
    printf("1. Candidate requests\n");
    printf("2. Voter requests\n");
    printf("3. Parliament Election 2050 - Results\n");
    printf("B. Back\n\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            candidateRequestsPage();
            break;
        /*case 2:
            voterRequestsPage();
            break;
        case 3:
            showResults();
            break;*/
        default:
            //mainMenu();
    }
}

void candidateRequestsPage() {
    system("cls"); // Clears the console screen (Windows only)
    printf("Candidate Requests\n\n");

    FILE *fp = fopen("candidatereq.txt", "r");
    if (fp == NULL) {
        printf("No candidate requests found.\n");
        system("pause");
        officerDashboard();
        return;
    }

    char line[200];
    int index = 1;

    // Display all requests
    while (fgets(line, sizeof(line), fp)) {
        char name[100], nic[20], party[50], candidateID[20];
        sscanf(line, "%[^|]|%[^|]|%[^|]|%s", name, nic, party, candidateID);
        printf("%d. %s | %s | %s | %s\n", index++, name, nic, party, candidateID);
    }
    fclose(fp);

    // Ask for action
    printf("\nA = Approve\nR = Reject\nB = Back\n\n");
    char choice;
    printf("Enter your choice: ");
    scanf(" %c", &choice);
    getchar(); // clear buffer

    if (choice == 'B' || choice == 'b') {
        officerDashboard();
        return;
    }

    // Reopen file to process first request
    fp = fopen("candidatereq.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    FILE *approved = fopen("candidates.txt", "a");

    int processed = 0;
    while (fgets(line, sizeof(line), fp)) {
        if (processed == 0) {
            char name[100], nic[20], party[50], candidateID[20];
            sscanf(line, "%[^|]|%[^|]|%[^|]|%s", name, nic, party, candidateID);

            if (choice == 'A' || choice == 'a') {
                fprintf(approved,"\n");
                fprintf(approved, "%s|%s|%s|%s|pass123\n", candidateID, name, nic, party); // default password
                printf("Approved: %s\n", name);
            } else if (choice == 'R' || choice == 'r') {
                printf("Rejected: %s\n", name);
            }
            processed = 1;
        } else {
            fputs(line, temp); // keep remaining requests
        }
    }

    fclose(fp);
    fclose(temp);
    fclose(approved);

    remove("candidatereq.txt");
    rename("temp.txt", "candidatereq.txt");

    system("pause");
    candidateRequestsPage(); // reload page
}

void main(){

    officerDashboard();
    candidateRequestsPage();

}