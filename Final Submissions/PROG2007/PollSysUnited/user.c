#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "user.h"

// Validation function to see if user is in the system
int validateUser(User *users, int numUsers) {

    // Variables needed for this function
    char inputUserName[30], inputUserPass[30];

    // Ask user to input userName and userPass
    printf("Enter username: ");
    scanf("%s", inputUserName);
    printf("Enter password: ");
    scanf("%s", inputUserPass);

    // Loop through the userList array to see if entered userName & userPass are valid
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].userName, inputUserName) == 0 && strcmp(users[i].userPass, inputUserPass) == 0) {
            return i;
        }
    }

    // If user not valid, return -1. Main will loop while -1 is returned and proceed once it's returned 0
    return -1;
}

void castVote(Candidate *candidates, int numCandidates) {

    printf("To cast your vote, please select one of the following candidates:");
    // Display a list of possible candidates for user to vote for
    for (int i = 0; i < numCandidates; i++) {
        printf("\n%d. %s %s | Party: %s", i+1, candidates[i].firstName, candidates[i].lastName, candidates[i].partyRep);
    }

    // Ask user to select one of the above candidates
    int userChoice;
    do {
        printf("\nYour choice: ");
        if (scanf("%d", &userChoice) != 1) { // Check for invalid input
            printf("Invalid input, please enter a valid number.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue; // Prompt user again
        }
        if (userChoice < 1 || userChoice > numCandidates) { // Check for out-of-range input
            printf("Invalid choice: Please enter a number between 1 - %d.\n", numCandidates);
        }
    } while (userChoice < 1 || userChoice > numCandidates);


    // Increment candidates vote count by 1.
    // Variable userChoice is an int type, so we need to subtract it by 1 to get the right index value
    candidates[userChoice-1].voteTally++;

    // Message to user thanking them for voting for the candidate
    printf("Your vote for %s %s representing the %s Party has been cast.\n", candidates[userChoice-1].firstName, candidates[userChoice-1].lastName, candidates[userChoice-1].partyRep);
    printf("For your security, you will now be logged out and session will be terminated.\n");
}

// Dummy list for users
User userList[30] = {
        {"j-halpert", "bigtuna", "Jim", "Halpert", "42 Linden Ave", 38},
        {"p-halpert", "smalltuna", "Pam", "Halpert", "42 Linden Ave", 35},
        {"r-howard", "fireguy", "Ryan", "Howard", "12 Pine St", 31},
        {"a-bernard", "cornellalum", "Andy", "Bernard", "1206 Main Rd", 37},
        {"s-hudson", "pretzelday", "Stanley", "Hudson", "195 Shell Dr", 58},
        {"p-l-vance", "bobvance", "Phyllis", "Lapin-Vance", "55 Road Way", 56},
        {"o-martinez", "actually", "Oscar", "Martinez", "28 Valley Peak", 52},
        {"k-malone", "famouschili", "Kevin", "Malone", "45 Skid Row", 48},
        {"a-martin", "sprinkles", "Angela", "Martin", "218 Fifth Ave", 41},
        {"m-palmer", "vodka@work", "Meredith", "Palmer", "55 Street Place", 43},
        {"c-bratton", "bobody", "Creed", "Bratton", "55 Linden Ave", 29},
        {"t-flenderson", "divorced", "Toby", "Flenderson", "742 Lean St", 42},
        {"k-kapoor", "howdareyou", "Kelly", "Kapoor", "903 Twenty Park", 28},
        {"e-hannon", "fosterhome", "Erin", "Hannon", "38 High Drive", 27},
        {"t-packer", "thepackman", "Todd", "Packer", "904 Tidy Lane", 46}
};