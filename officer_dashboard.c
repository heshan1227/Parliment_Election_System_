// officer_dashboard.c
#include <stdio.h>
#include <stdlib.h>

// Dummy forward declarations
void candidateRequestsPage();
void voterRequestsPage();
void showResults();
void mainMenu();

void officerDashboard() {
    int choice;

    system("cls");
    printf("Hello! Mr./Mrs. officer1\n\n");
    printf("1. Candidate requests\n");
    printf("2. Voter requests\n");
    printf("3. Parliament Election 2050 - Results\n");
    printf("B. Back\n\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            candidateRequestsPage();
            break;
        case 2:
            voterRequestsPage();
            break;
        case 3:
            showResults();
            break;
        default:
            mainMenu();
    }
}