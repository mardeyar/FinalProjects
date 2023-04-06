#ifndef POLLSYSUNITED_OFFICER_H
#define POLLSYSUNITED_OFFICER_H

#include "candidate.h"

typedef struct Officer {
    char officerName[30];
    char officerPass[30];
} Officer;

void displayVoteCount(Candidate *candidates);
int validateOfficer(Officer *officerList);
extern Officer officerList[1];

#endif //POLLSYSUNITED_OFFICER_H