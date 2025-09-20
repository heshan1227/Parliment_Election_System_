// voter_login.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VOTER_FILE "voters.txt"

// Forward declarations
void voterDashboard(char nic[], char name[]);
void voterGateway();

void voterLoginPage() {
    char username[20], password[20], line[200];
    int found = 0;

    system("cls"); // Clear screen
    printf("Voter Login\n");
    printf("USERNAME (Use Your NIC): ");
    scanf("%s", username);
    printf("PASSWORD: ");
    scanf("%s", password);

    // Open voters.txt for reading
    FILE *fp = fopen(VOTER_FILE, "r");
    if (fp == NULL) {
        printf("Error opening voters file.\n");
        system("pause");
        voterGateway();
        return;
    }

    // Search for matching NIC and password
    while (fgets(line, sizeof(line), fp)) {
        char nic[20], name[100], filePass[20];
        sscanf(line, "%[^|]|%[^|]|%s", nic, name, filePass);

        if (strcmp(username, nic) == 0 && strcmp(password, filePass) == 0) {
            found = 1;
            fclose(fp);
            voterDashboard(nic, name); // Go to dashboard
            return;
        }
    }

    fclose(fp);

    // If not found, show error and return to gateway
    printf("!!! Invalid USERNAME/PASSWORD !!!\n");
    system("pause");
    voterGateway();
}