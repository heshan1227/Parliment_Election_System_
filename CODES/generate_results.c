// generate_results.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VOTES_FILE "votes.txt"
#define CANDIDATE_FILE "candidates.txt"
#define RESULT_FILE "result.txt"

typedef struct {
    char candidateID[20];
    char name[100];
    char party[50];
    int votes;
} Candidate;

Candidate candidates[100];
int candidateCount = 0;

void loadCandidates() {
    FILE *fp = fopen(CANDIDATE_FILE, "r");
    if (fp == NULL) {
        printf("Error opening candidates file.\n");
        return;
    }

    char line[200];
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^|]|%[^|]|%*[^|]|%[^|]|%*s",
               candidates[candidateCount].candidateID,
               candidates[candidateCount].name,
               candidates[candidateCount].party);
        candidates[candidateCount].votes = 0;
        candidateCount++;
    }

    fclose(fp);
}

void countVotes() {
    FILE *fp = fopen(VOTES_FILE, "r");
    if (fp == NULL) {
        printf("No votes recorded.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        char voterNIC[20], votedID[20];
        sscanf(line, "%[^|]|%s", voterNIC, votedID);

        for (int i = 0; i < candidateCount; i++) {
            if (strcmp(votedID, candidates[i].candidateID) == 0) {
                candidates[i].votes++;
                break;
            }
        }
    }

    fclose(fp);
}

// Sort candidates by vote count (descending)
void sortCandidates() {
    for (int i = 0; i < candidateCount - 1; i++) {
        for (int j = i + 1; j < candidateCount; j++) {
            if (candidates[j].votes > candidates[i].votes) {
                Candidate temp = candidates[i];
                candidates[i] = candidates[j];
                candidates[j] = temp;
            }
        }
    }
}

// Write result.txt
void writeResults() {
    FILE *fp = fopen(RESULT_FILE, "w");
    if (fp == NULL) {
        printf("Error creating result file.\n");
        return;
    }

    for (int i = 0; i < candidateCount; i++) {
        fprintf(fp, "%d. %s | %s | %d\n",
                i + 1,
                candidates[i].name,
                candidates[i].party,
                candidates[i].votes);
    }

    fclose(fp);
    printf("Results generated successfully.\n");
}

void generateResults() {
    system("cls"); // Clear screen
    loadCandidates();
    countVotes();
    sortCandidates();
    writeResults();
    system("pause");
    return;
}