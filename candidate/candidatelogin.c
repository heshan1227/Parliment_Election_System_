#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*void candidateDashboard(char candidateID[], char name[]);
void candidateGateway();*/

void candidateLoginPage() {
    system("cls");
    char username[20], password[20], line[200];
    

    printf("\t\t\t\t\t***Welcome to Candidate Login***\n\n\n");
    printf("USERNAME (EX- U1234c): ");
    scanf("%s", username);
    printf("PASSWORD: ");
    scanf("%s", password);

    FILE *fp = fopen("candidates.txt", "r");
    if (fp == NULL) {
        printf("Error opening candidates file.\n");
        //candidateGateway();
        return;
    }

    while (fgets(line, sizeof(line), fp)) {
        char candidateID[20], name[100], nic[20], party[50], filePass[20];
        sscanf(line, "%[^|]|%[^|]|%[^|]|%[^|]|%s", candidateID, name, nic, party, filePass);

        if (strcmp(username, candidateID) == 0 && strcmp(password, filePass) == 0) {
            printf("Login Succesfully!!");
            fclose(fp);
            //candidateDashboard(candidateID, name); // Go to dashboard
            return;
        }
    }

    fclose(fp);

    
    printf("!!! Invalid USERNAME/PASSWORD !!!\n");
    system("pause");
    //candidateGateway();
}

void main(){


 candidateLoginPage();




}