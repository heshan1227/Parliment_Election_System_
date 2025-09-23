// candidate_dashboard.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VOTES_FILE "votes.txt"
#define RESULT_FILE "result.txt"
#define CANDIDATE_FILE "candidates.txt"

// Forward declaration
void candidateGateway();

void candidateDashboard(char candidateID[], char name[]) {
    char choice;

    while (1) {
        system("cls"); // Clear screen
        printf("Hello! Mr./Mrs. %s\n\n\n", name);
        printf("1 View My Votes\n");
        printf("2 View Results\n");
        printf("B = Back\n\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        if (choice == '1') {
            // Count votes for this candidate
            FILE *fp = fopen(VOTES_FILE, "r");
            int voteCount = 0;
            char line[100];

            if (fp == NULL) {
                printf("No votes recorded yet.\n");
            } else {
                while (fgets(line, sizeof(line), fp)) {
                    char voterNIC[20], votedID[20];
                    sscanf(line, "%[^|]|%s", voterNIC, votedID);
                    if (strcmp(votedID, candidateID) == 0) {
                        voteCount++;
                    }
                }
                fclose(fp);
                printf("Your votes: %d\n", voteCount);
            }
            system("pause");

        } else if (choice == '2') {
            // Show results if available
            FILE *fp = fopen(RESULT_FILE, "r");
            char line[200];

            if (fp == NULL) {
                printf("Parliament Election 2050 – Results —Not ready yet—\n");
            } else {
                printf("Parliament Election 2050 – Results\n");
                while (fgets(line, sizeof(line), fp)) {
                    printf("%s", line);
                }
                fclose(fp);
            }
            system("pause");

        } else if (choice == 'B' || choice == 'b') {
            system("cls");
            printf("Returning to Candidate Gateway...\n");
            system("pause");
            candidateGateway(); //  Go back
            return; //  Exit dashboard completely

        } else {
            printf("Invalid selection. Try again.\n");
            system("pause");
        }
    }
}