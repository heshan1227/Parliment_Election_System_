// voter_dashboard.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VOTER_FILE "voters.txt"
#define CANDIDATE_FILE "candidates.txt"
#define VOTES_FILE "votes.txt"
#define RESULT_FILE "result.txt"

// Forward declarations
void voterGateway();

// Check if voter has already voted
int hasVoted(char voterNIC[]) {
    FILE *fp = fopen(VOTER_FILE, "r");
    char line[200];

    while (fgets(line, sizeof(line), fp)) {
        char nic[20], name[100], pass[20], status[2];
        sscanf(line, "%[^|]|%[^|]|%[^|]|%s", nic, name, pass, status);
        if (strcmp(nic, voterNIC) == 0) {
            fclose(fp);
            return strcmp(status, "1") == 0;
        }
    }

    fclose(fp);
    return 0;
}

// Mark voter as voted
void markVoterAsVoted(char voterNIC[]) {
    FILE *fp = fopen(VOTER_FILE, "r");
    FILE *temp = fopen("temp.txt", "w");
    char line[200];

    while (fgets(line, sizeof(line), fp)) {
        char nic[20], name[100], pass[20], status[2];
        sscanf(line, "%[^|]|%[^|]|%[^|]|%s", nic, name, pass, status);

        if (strcmp(nic, voterNIC) == 0) {
            fprintf(temp, "%s|%s|%s|1\n", nic, name, pass); // mark as voted
        } else {
            fprintf(temp, "%s", line); // keep original
        }
    }

    fclose(fp);
    fclose(temp);
    remove(VOTER_FILE);
    rename("temp.txt", VOTER_FILE);
}

// Voting page
void votePage(char voterNIC[]) {
    system("cls");
    printf("Cast Your Vote\n");

    if (hasVoted(voterNIC)) {
        printf("\n!!! You are already voted !!!\n");
        system("pause");
        return;
    }

    FILE *fp = fopen(CANDIDATE_FILE, "r");
    if (fp == NULL) {
        printf("No candidates available.\n");
        system("pause");
        return;
    }

    char line[200];
    printf("Available Candidates:\n");
    while (fgets(line, sizeof(line), fp)) {
        char candidateID[20], name[100], nic[20], party[50], pass[20];
        sscanf(line, "%[^|]|%[^|]|%[^|]|%[^|]|%s", candidateID, name, nic, party, pass);
        printf("ID: %s | Name: %s | Party: %s\n", candidateID, name, party);
    }
    fclose(fp);

    char selectedID[20];
    printf("\nEnter Candidate ID to vote: ");
    scanf("%s", selectedID);

    fp = fopen(VOTES_FILE, "a");
    if (fp == NULL) {
        printf("Error saving vote.\n");
    } else {
        fprintf(fp, "%s|%s\n", voterNIC, selectedID);
        fclose(fp);
        markVoterAsVoted(voterNIC);
        printf("Vote cast successfully!\n");
    }

    system("pause");
}

// Voter dashboard
void voterDashboard(char nic[], char name[]) {
    char choice;

    while (1) {
        system("cls");
        printf("Voter Dashboard\n");
        printf("Welcome, %s!\n", name);
        printf("1 Cast Vote\n");
        printf("2 View Results\n");
        printf("B = Back\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        if (choice == '1') {
            votePage(nic);

        } else if (choice == '2') {
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
            voterGateway();
            return;

        } else {
            printf("Invalid selection. Try again.\n");
            system("pause");
        }
    }
}