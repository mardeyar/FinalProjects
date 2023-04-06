#ifndef POLLSYSUNITED_ADMIN_H
#define POLLSYSUNITED_ADMIN_H

#include "user.h"

typedef struct {
    char adminName[30];
    char adminPass[30];
} Admin;

int validateAdmin(Admin *admins);
void addUser(User *users, int *numUsers);
void removeUser(User *users, int *numUsers);
void displayUsers(User *users);
extern Admin adminList[1];

#endif //POLLSYSUNITED_ADMIN_H