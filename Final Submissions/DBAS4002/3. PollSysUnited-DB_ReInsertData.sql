-- DBAS4007 - Assignment 3: PollSys United DB
-- DDL Script designed to re-insert initial dummy data back into the DB after truncation
-- Designed by Mark Deyarmond | April 04, 2023
-- DBName: PollSysUnited.bak

-- Insert data into Users table
INSERT INTO Users (UserID, FirstName, LastName, Address, Age)
VALUES
(101, 'Jim', 'Halpert', '42 Linden Ave', 38),
(102, 'Pam', 'Halpert', '42 Linden Ave', 35),
(103, 'Ryan', 'Howard', '12 Pine St', 31),
(104, 'Andy', 'Bernard', '1206 Main Rd', 37),
(105, 'Stanley', 'Hudson', '195 Shell Dr', 58),
(106, 'Phyllis', 'Lapin-Vance', '55 Road Way', 56),
(107, 'Oscar', 'Martinez', '28 Valley Peak', 52),
(108, 'Kevin', 'Malone', '45 Skid Row', 48),
(109, 'Angela', 'Martin', '218 Fifth Ave', 41),
(110, 'Meredith', 'Palmer', '55 Street Place', 43),
(111, 'Creed', 'Bratton', '55 Linden Ave', 29),
(112, 'Toby', 'Flenderson', '742 Lean St', 42),
(113, 'Kelly', 'Kapoor', '903 Twenty Park', 28),
(114, 'Erin', 'Hannon', '38 High Drive', 27),
(115, 'Todd', 'Packer', '904 Tidy Lane', 46);

-- Insert data into UserLogin table
INSERT INTO UserLogin (UserID, UserName, UserPass)
VALUES
(101, 'j-halpert', 'bigtuna'),
(102, 'p-halpert', 'smalltuna'),
(103, 'r-howard', 'fireguy'),
(104, 'a-bernard', 'cornellalum'),
(105, 's-hudson', 'pretzelday'),
(106, 'p-l-vance', 'bobvance'),
(107, 'o-martinez', 'actually'),
(108, 'k-malone', 'famouschili'),
(109, 'a-martin', 'sprinkles'),
(110, 'm-palmer', 'vodka@work'),
(111, 'c-bratton', 'bobody'),
(112, 't-flenderson', 'divorced'),
(113, 'k-kapoor', 'howdareyou'),
(114, 'e-hannon', 'fosterhome'),
(115, 't-packer', 'thepackman');

-- Insert candidates into tables
INSERT INTO Candidates (CandidateID, FirstName, LastName, PartyRep)
VALUES
(201, 'Michael', 'Scott', 'Liberal'),
(202, 'Dwight', 'Schrute', 'Conservative'),
(203, 'David', 'Wallace', 'NDP');

-- Insert data into tables for Admin, PollingOfficer & their login info
INSERT INTO Admin (AdminID, AdminFirstName, AdminLastName)
VALUES (301, 'Holly', 'Flax');

INSERT INTO AdminLogin (AdminID, AdminName, AdminPass)
VALUES (301, 'ADMIN', 'gravy9001');

INSERT INTO PollingOfficer (OfficerID, OfficerFirstName, OfficerLastName)
VALUES (901, 'Gabe', 'Lewis');

INSERT INTO OfficerLogin (OfficerID, OfficerName, OfficerPass)
VALUES (901, 'POLLSYS-T1', 'dummypass');

-- Insert some dummy votes for Michael Scott (CandidateID = 201)
INSERT INTO VoteCount (UserID, CandidateID)
SELECT TOP 2 UserID, 201
FROM Users
ORDER BY NEWID(); -- Randomize the selection of users

-- Insert some dummy votes for Dwight Schrute (CandidateID = 202)
INSERT INTO VoteCount (UserID, CandidateID)
SELECT TOP 9 UserID, 202
FROM Users
ORDER BY NEWID(); -- Randomize the selection of users

-- Insert some dummy votes for David Wallace (CandidateID = 203)
INSERT INTO VoteCount (UserID, CandidateID)
SELECT TOP 4 UserID, 203
FROM Users
ORDER BY NEWID(); -- Randomize the selection of users