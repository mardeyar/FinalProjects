#include <stdio.h>
#include <stdbool.h>
#include "admin.h"
#include "candidate.h"
#include "officer.h"
#include "user.h"

int main() {

    bool isRunning = true;

    // Display welcome message to user
    printf("Welcome to PollSys United! Please make a selection:\n");

    // Create a while loop to keep the program running until user exits
    while (isRunning) {
        printf("\n1. User Panel | 2. Admin Panel | 3. Polling Officer | 4. Exit\n");
        printf("Your choice: ");
        int userChoice;
        scanf("%d", &userChoice);

        // Switch statement to run through given scenarios
        switch (userChoice) {
            case 1: { // User panel
                // Validation checker for userName and userPass
                int index = -1;
                while (index == -1) {
                    index = validateUser(userList, sizeof(userList) / sizeof(userList[0]));
                    if (index != -1) {
                        printf("\nWelcome, %s %s!\n", userList[index].firstName, userList[index].lastName);
                    } else {
                        printf("Invalid credentials: Please try again.\n");
                    }
                }
                castVote(candidateList, sizeof(candidateList) / sizeof(candidateList[0]));
                break;
            }
            case 2: { // Admin panel
                // Validation checker for adminName and adminPass
                int index = -1;
                while (index == -1) {
                    index = validateAdmin(adminList);
                    if (index != -1) {
                        printf("\nWelcome, ADMIN!\n");
                    } else {
                        printf("Invalid credentials: Please try again.\n");
                    }
                }

                // Variables to use within admin switch
                int adminChoice;
                int numUsers = sizeof(&userList);
                bool adminSessionActive = true;

                while (adminSessionActive) {
                    // Admin options
                    printf("\nPlease choose an option\n");
                    printf("1. Add user | 2. Remove user | 3. Display User | 4. Log out\n");
                    printf("Your choice: ");
                    scanf("%d", &adminChoice);

                    // Cycle through the options, which one did admin choose
                    switch (adminChoice) {
                        case 1: {
                            addUser(userList, &numUsers);
                            break;
                        }
                        case 2: {
                            removeUser(userList, &numUsers);
                            break;
                        }
                        case 3: {
                            displayUsers(userList);
                            break;
                        }
                        case 4: {
                            printf("Session terminated.\n");
                            adminSessionActive = false;
                            break;
                        }
                        default: {
                            printf("Invalid option: Please try again.");
                            break;
                        }
                    }
                }
                break;
            }
            case 3: { // Polling officer: gets the total vote count so far
                // Validation checker for officerName and officerPass
                int index = -1;
                while (index == -1) {
                    index = validateOfficer(officerList);
                    if (index != -1) {
                        printf("\n**** Welcome %s ****", officerList[0].officerName);
                    } else {
                        printf("Invalid credentials: Please try again.\n");
                    }
                }
                displayVoteCount(candidateList);
                break;
            }
            case 4: { // Exit program
                isRunning = false;
                printf("\nThank you for using PollSys United, goodbye!\n");
                break;
            }
            default: { // Error handling
                printf("Invalid option: Please try again.");
                break;
            }
        }
    }
    return 0;
}