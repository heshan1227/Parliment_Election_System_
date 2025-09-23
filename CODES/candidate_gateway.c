// candidate_gateway.c
#include <stdio.h>
#include <stdlib.h>

// Dummy declarations
void candidateLoginPage();
void candidateRegistrationPage();
void showResults();
void mainMenu();

void candidateGateway() {
    int choice;

    system("cls"); // Clears the console screen (Windows only)
    printf("\t\t\t\t\t***Welcome To Candidate Login Page***\n\n\n");
    printf("1. LOGIN\n");
    printf("2. Register as a candidate\n");
    printf("3. View Results\n");
    printf("B. Back\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            candidateLoginPage();
            break;
        case 2:
            candidateRegistrationPage();
            break;
        case 3:
            showResults();
            break;
	case 'b':
            mainMenu();
            break;
	case 'B':
            mainMenu();
        default:
            mainMenu();
    }
}