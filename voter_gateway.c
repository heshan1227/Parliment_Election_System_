// voter_gateway.c
#include <stdio.h>
#include <stdlib.h>

// Dummy declarations
void voterLoginPage();
void voterRegistrationPage();
void showResults();
void mainMenu();

void voterGateway() {
    int choice;

    system("cls"); // Clears the console screen
    printf("***Welcome To Voter Login Page***\n");
    printf("1. LOGIN\n");
    printf("2. Register as a voter\n");
    printf("3. View Results\n");
    printf("B. Back\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            voterLoginPage();
            break;
        case 2:
            voterRegistrationPage();
            break;
        case 3:
            showResults();
            break;
        default:
            mainMenu();
    }
}