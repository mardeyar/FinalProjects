#ifndef POLLSYSUNITED_CANDIDATE_H
#define POLLSYSUNITED_CANDIDATE_H

typedef struct Candidate {
    char firstName[30];
    char lastName[30];
    char partyRep[50];
    int voteTally;
} Candidate;

extern Candidate candidateList[3];

#endif //POLLSYSUNITED_CANDIDATE_H