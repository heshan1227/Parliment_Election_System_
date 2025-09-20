// voter_dashboard.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VOTES_FILE "votes.txt"
#define RESULT_FILE "result.txt"
#define CANDIDATE_FILE "candidates.txt"

// Dummy forward declaration
void voterGateway();

void voterDashboard(char nic[], char name[]) {
    int choice;
    char line[200];

    system("cls");
    printf("Voter Dashboard\n");
    printf("Hello! Mr./Mrs. %s\n", name);
    printf("1. Vote\n");
    printf("2. View Results\n");
    printf("B. Back\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        char candidateID[20];
        int alreadyVoted = 0;

        // Check if voter already voted
        FILE *fp = fopen(VOTES_FILE, "r");
        if (fp != NULL) {
            while (fgets(line, sizeof(line), fp)) {
                char voterNIC[20], votedID[20];
                sscanf(line, "%[^|]|%s", voterNIC, votedID);
                if (strcmp(voterNIC, nic) == 0) {
                    alreadyVoted = 1;
                    break;
                }
            }
            fclose(fp);
        }

        if (alreadyVoted) {
            printf("You have already voted.\n");
        } else {
            printf("Enter Candidate_ID (EX- U1234c): ");
            scanf("%s", candidateID);

            // Validate Candidate_ID
            int valid = 0;
            fp = fopen(CANDIDATE_FILE, "r");
            if (fp != NULL) {
                while (fgets(line, sizeof(line), fp)) {
                    char id[20];
                    sscanf(line, "%[^|]", id);
                    if (strcmp(candidateID, id) == 0) {
                        valid = 1;
                        break;
                    }
                }
                fclose(fp);
            }

            if (valid) {
                fp = fopen(VOTES_FILE, "a");
                fprintf(fp, "%s|%s\n", nic, candidateID);
                fclose(fp);
                printf("Your vote has been recorded.\n");
            } else {
                printf("Invalid Candidate_ID.\n");
            }
        }

        system("pause");
        voterDashboard(nic, name);
    } else if (choice == 2) {
        FILE *fp = fopen(RESULT_FILE, "r");
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
        voterDashboard(nic, name);
    } else {
        voterGateway();
    }
}