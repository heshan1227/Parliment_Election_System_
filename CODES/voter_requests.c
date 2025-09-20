// voter_requests.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REQUEST_FILE "voter_requests.txt"
#define APPROVED_FILE "voters.txt"

// Forward declaration
void officerDashboard();

void voterRequestsPage() {
    system("cls"); // Clear screen
    printf("Voter Requests\n");

    FILE *fp = fopen(REQUEST_FILE, "r");
    if (fp == NULL) {
        printf("No voter requests found.\n");
        system("pause");
        officerDashboard();
        return;
    }

    char line[200];
    int index = 1;

    // Display all requests
    while (fgets(line, sizeof(line), fp)) {
        char name[100], nic[20];
        sscanf(line, "%[^|]|%s", name, nic);
        printf("%d. %s | %s\n", index++, name, nic);
    }
    fclose(fp);

    // Ask for action
    printf("\nA = Approve\nR = Reject\nB = Back\n");
    char choice;
    printf("Enter your choice: ");
    scanf(" %c", &choice);
    getchar(); // clear buffer

    if (choice == 'B' || choice == 'b') {
        officerDashboard();
        return;
    }

    // Reopen file to process first request
    fp = fopen(REQUEST_FILE, "r");
    FILE *temp = fopen("temp.txt", "w");
    FILE *approved = fopen(APPROVED_FILE, "a");

    int processed = 0;
    while (fgets(line, sizeof(line), fp)) {
        if (processed == 0) {
            char name[100], nic[20];
            sscanf(line, "%[^|]|%s", name, nic);

            if (choice == 'A' || choice == 'a') {
                fprintf(approved, "%s|%s|pass123\n", nic, name); // default password
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

    remove(REQUEST_FILE);
    rename("temp.txt", REQUEST_FILE);

    system("pause");
    voterRequestsPage(); // reload page
}