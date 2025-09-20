// candidate_dashboard.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VOTES_FILE "votes.txt"

// Dummy forward declaration
void candidateGateway();

void candidateDashboard(char candidateID[], char name[]) {
    int choice;
    int voteCount = 0;
    char line[100];

    system("cls"); // Clears the console screen
    printf("Candidate Dashboard\n");
    printf("Hello! Mr./Mrs. %s\n", name);
    printf("1. View My Votes\n");
    printf("2. View Results\n");
    printf("B. Back\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        FILE *fp = fopen(VOTES_FILE, "r");
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
        candidateDashboard(candidateID, name);
    } else if (choice == 2) {
        FILE *fp = fopen("result.txt", "r");
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
        candidateDashboard(candidateID, name);
    } else {
        candidateGateway();
    }
}