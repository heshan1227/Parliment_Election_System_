#include <stdio.h>
#include <stdlib.h>

void page01() {
    printf("Page 01: Main Menu\n");
    printf("1 Officer\n2 Candidate\n3 Voter\n");
    printf("Enter your choice: ");
}

void page02() {
    system("cls"); // Clears the console
    printf("Page 02: Role Gateway\n");
    printf("Welcome to Candidate Login Page\n");
    // Continue with inputs...
}

int main() {
    int choice;
    page01();
    scanf("%d", &choice);

    if (choice == 2) {
        page02(); // Moves to candidate page
    }

    return 0;
}
