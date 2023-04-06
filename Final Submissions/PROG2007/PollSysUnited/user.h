#ifndef POLLINGSYSTEM_USER_H
#define POLLINGSYSTEM_USER_H

#include "candidate.h"

typedef struct {
    char userName[30];
    char userPass[30];
    char firstName[30];
    char lastName[30];
    char address[100];
    int age;
} User;

int validateUser(User *users, int numUsers);
void castVote(Candidate *candidates, int numCandidates);
extern User userList[30];

#endif //POLLINGSYSTEM_USER_H