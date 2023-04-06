# PollSys United: Polling Station Software
PollSys United was designed for small voting system where only a handful of voters and candidates are needed. It features a user panel, admin panel and polling officer panel, each with it's own use case functions.

## How to use
For registered voters: use the credentials the given to you by the polling officer to log in and cast your vote. Simply put, the system will allow a log-in followed by a vote cast. For security reasons, once you cast a vote, your session will be terminated and you will be logged out.

For ADMIN: Use the credentials given to you by the polling officer to log in and use the ADMIN functions. Functions available to an ADMIN are add user, remove user and display user list. 

For Officer: Use inital dummy credentials found in appropriate SQL script to log in. Since officer has no other function, votes will be counted and displayed immediately when officer logs in.

## Known bugs
[ * ] Add user function currently removing existing user to make room for new user

[ * ] Remove user function successfully removes a user but duplicates another in the process

## File structure

#### DBAS4002
Contains: database design doc, DB diagram & SQL script files

#### PROG2007
Contains: User guide doc, software flowchart & project folder w/ source code

#### SAAD1001
Contains: Class diagram for software and system analysis on polling software
