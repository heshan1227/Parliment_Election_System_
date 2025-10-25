// main_menu.c
#include <stdio.h>
#include <stdlib.h>

// Functions
void officerLoginPage();
void candidateGateway();
void voterGateway();

void mainMenu() {
    int choice;

    while (1) {
        system("cls"); // Clear screen
        printf("\t\t\t\t\tParliament Election - 2050\n\n");
        printf("Choose Your Profile Type...\n");
        printf(" 1. Officer\n");
        printf(" 2. Candidate\n");
        printf(" 3. Voter\n");
        printf(" 0. Exit\n\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                officerLoginPage();
                break;
            case 2:
                candidateGateway();
                break;
            case 3:
                voterGateway();
                break;
            case 0:
                exit(0); // Exit program
            default:
                printf("Invalid selection. Try again.\n");
                system("pause");
        }
    }
}

int main() {
    mainMenu();
    return 0;
}