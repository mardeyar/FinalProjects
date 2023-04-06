#include <stdio.h>
#include <string.h>
#include "officer.h"
#include "candidate.h"

void displayVoteCount(Candidate *candidates) {
    printf("\nCandidate Vote Count\n");
    printf("============================\n");
    for (int i = 0; i < 3; i++) {
        printf("%s %s: %d\n", candidates[i].firstName, candidates[i].lastName, candidates[i].voteTally);
    }
}

int validateOfficer(Officer *officerList) {

    // Variables needed for this to work
    char officerName[30], officerPass[30];

    // Gather credentials from officer
    printf("Enter officer name: ");
    scanf("%s", officerName);
    printf("Enter officer password: ");
    scanf("%s", officerPass);

    // Use some if logic to determine validity of officer log-in
    if (strcmp(officerList[0].officerName, officerName) == 0 && strcmp(officerList[0].officerPass, officerPass) == 0) {
        // Valid officer credentials
        return 1;
    } else {
        // Invalid officer credentials
        return -1;
    }
}

// Dummy list for the polling officer
Officer officerList[1] = {
        {"POLLSYS-T1", "dummypass"}
};