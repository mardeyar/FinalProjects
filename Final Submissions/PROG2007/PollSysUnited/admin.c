#include <stdio.h>
#include <string.h>
#include "admin.h"
#include "user.h"

// Validation function to see if admin is in the system
int validateAdmin(Admin *admins) {

    // Variables needed for this function
    char adminName[30], adminPass[30];

    // Get credentials from admin
    printf("Enter admin name: ");
    scanf("%s", adminName);
    printf("Enter admin pass: ");
    scanf("%s", adminPass);

    // Use if logic to see if user credentials are valid
    if (strcmp(admins[0].adminName, adminName) == 0 && strcmp(admins[0].adminPass, adminPass) == 0) {
        // Valid admin credentials
        return 1;
    } else {
        // Invalid admin credentials
        return -1;
    }
}

void addUser(User *users, int *numUsers) {

    // Create variable 'newUser' of type 'User'
    User newUser;

    // Get info from admin to create a new user
    printf("\nAssign username: ");
    scanf("%s", newUser.userName);
    printf("Assign password: ");
    scanf("%s", newUser.userPass);
    printf("First name: ");
    scanf("%s", newUser.firstName);
    printf("Last name: ");
    scanf("%s", newUser.lastName);
    printf("Address: ");
    scanf("%*c"); // Consume the newline character so program won't skip over address entry
    fgets(newUser.address, 100, stdin);
    printf("Age: ");
    scanf("%d", &newUser.age);

    // Check if age is less than 18
    if (newUser.age < 18) {
        printf("User must be 18 years or older to be added. User not added.\n");
        return;
    }

    // Add newly created user to userList array
    users[*numUsers] = newUser;

    // Update the number of users
    (*numUsers)++;
}

void removeUser(User *users, int *numUsers) {

    // Variables needed for this function
    char userName[30];

    // Get info from admin to remove user
    printf("Enter username to be removed: ");
    scanf("%s", userName);

    // Loop through userList to find the user to remove
    int index = -1;
    for (int i = 0; i < *numUsers; ++i) {
        if (strcmp(users[i].userName, userName) == 0) {
            index = i;
            break;
        }
    }

    // If the userName exists, remove user
    if (index != -1) {
        for (int i = index; i < (*numUsers) - 1; i++) {
            users[i] = users[i + 1];
        }
        (*numUsers)--;
        printf("User %s has been removed.\n", userName);
    } else {
        printf("User %s not found.\n", userName);
    }
}

void displayUsers(User *users) {
    // Loop through users and print out
    printf("\nEnter the UserID of the user you would like to edit\n");
    for (int i = 0; i < 30; i++) {
        printf("UserID #%d: %s %s\n", i + 1, users[i].firstName, users[i].lastName);
    }
}


// Dummy list for admins
Admin adminList[1] = {
        {"ADMIN", "gravy9001"}
};