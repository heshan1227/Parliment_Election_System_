#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define FILE_PATH "C:\\Users\\ASUS\\Desktop\\c prog\\Parliment_Election_System_\\.txt files\\candidate_requests.txt"

void candidateRegistration() {
    char name[50];
    char nic[20];
    char party[50];
    char candidate_id[20];
    char line[200];
    bool exists = false;
    FILE *file;

    printf("Name (Ex-Tharuka_perera): ");
    getchar(); // clear buffer
    scanf(" %s", &name);

    printf("NIC: ");
    scanf(" %s", &nic);

    printf("Party (Ex-Unity_party): ");
    scanf(" %s", &party);

    if ((strcmp(party, "Unity_party") == 0) || (strcmp(party, "Freedom_party") == 0) || (strcmp(party, "River_party") == 0)) {
        printf("Candidate_ID (Ex-U2345c): ");
        scanf(" %s", &candidate_id);

        // Step 1: Check if candidate_id already exists
        file = fopen(FILE_PATH, "r");
        if (file != NULL) {
            while (fgets(line, sizeof(line), file)) {
                if (strstr(line, candidate_id) != NULL) {
                    exists = true;
                    break;
                }
            }
            fclose(file);
        }

        // Step 2: If exists, show message
        if (exists) {
            printf("❌ Candidate ID already exists!\n");
        } else {
            // Step 3: Append new candidate
            file = fopen(FILE_PATH, "a");
            if (file != NULL) {
                fprintf(file, "\n%s|%s|%s|%s", name, nic, party, candidate_id);
                fclose(file);
                printf("\n✅ Request submitted successfully....\n");
            } else {
                printf("❌ Error opening file!\n");
            }
        }
    } else {
        printf("Invalid party!!\n");
    }
}



// Main Menu
int main() {
    int page;

    while (1) {
        printf("\n--- Main Menu ---\n");
        printf("1. Candidate Registration (Page 03)\n");
        printf("2. Candidate Dashboard (Page 04)\n");
        printf("3. Voter Gateway (Page 02)\n");
        printf("0. Exit\n");
        printf("Choose a page: ");
        scanf("%d", &page);

        switch (page) {
            case 1:
                candidateRegistration();
                break;
            case 2:
               // candidateDashboard();
                break;
            case 3:
               // voterGateway();
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}
