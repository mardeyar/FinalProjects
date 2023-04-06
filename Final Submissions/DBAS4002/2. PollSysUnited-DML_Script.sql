-- DBAS4007 - Assignment 3: PollSys United DB
-- DML script to create and run queries based on assignment needs
-- Designed by Mark Deyarmond | April 04, 2023
-- DBName: PollSysUnited.bak

-- Query #1: Update voter information

USE [PollSysUnited]
GO

BEGIN TRAN UpdateUserInfo
	UPDATE Users
	SET FirstName = 'Jim', LastName = 'Halpert', Address = '1344 Plain St', Age = 39
	WHERE UserID = 101;

-- Check if the update is successful
SELECT * FROM Users WHERE UserID = 101;
IF @@ROWCOUNT > 0
	BEGIN
	COMMIT TRAN UpdateUserInfo;
	END
ELSE
	BEGIN
	ROLLBACK TRAN UpdateUserInfo;
END

-- Query #2: Update voter login credentials

USE [PollSysUnited]
GO

BEGIN TRAN UpdateLoginCredentials
	UPDATE UserLogin
	SET UserName = 'p-lapin', UserPass = 'townsweetie'
	WHERE UserID = 106;

-- Check if the update is successful
SELECT * FROM UserLogin WHERE UserID = 106;

IF @@ROWCOUNT > 0
	BEGIN
	COMMIT TRAN UpdateLoginCredentials;
	PRINT 'Login credentials updated successfully.'
	END
ELSE
	BEGIN
	ROLLBACK TRAN UpdateLoginCredentials;
	PRINT 'Error updating login credentials.'
	END

-- Query #3: Delete a specific user from the database

USE [PollSysUnited]
GO

BEGIN TRAN DeleteUser
	DELETE FROM VoteCount WHERE UserID = 112;
	DELETE FROM UserLogin WHERE UserID = 112;
	DELETE FROM Users WHERE UserID = 112;

-- Check if the deletion is successful
SELECT * FROM Users WHERE UserID = 112;

IF @@ROWCOUNT = 0
	BEGIN
	COMMIT TRAN DeleteUser;
	PRINT 'User deleted successfully.'
	END
ELSE
	BEGIN
	ROLLBACK TRAN DeleteUser;
	PRINT 'Error deleting user.'
	END

-- Query #4: Clear all the data records without deleting the schema 

USE [PollSysUnited]
GO

-- Drop foreign keys from all tables
ALTER TABLE UserLogin DROP CONSTRAINT fk_UserLogin_Users
ALTER TABLE AdminLogin DROP CONSTRAINT fk_AdminLogin_Admin
ALTER TABLE OfficerLogin DROP CONSTRAINT fk_OfficerLogin_Officer
ALTER TABLE VoteCount DROP CONSTRAINT fk_Users
ALTER TABLE VoteCount DROP CONSTRAINT fk_Candidates

BEGIN TRAN ClearData

-- Truncate all the tables
TRUNCATE TABLE Users;
TRUNCATE TABLE UserLogin;
TRUNCATE TABLE Candidates;
TRUNCATE TABLE [Admin];
TRUNCATE TABLE AdminLogin;
TRUNCATE TABLE PollingOfficer;
TRUNCATE TABLE OfficerLogin;
TRUNCATE TABLE VoteCount;

-- Check if the truncation is successful
SELECT COUNT(*) FROM Users;
SELECT COUNT(*) FROM UserLogin;
SELECT COUNT(*) FROM Candidates;
SELECT COUNT(*) FROM [Admin];
SELECT COUNT(*) FROM AdminLogin;
SELECT COUNT(*) FROM PollingOfficer;
SELECT COUNT(*) FROM OfficerLogin;
SELECT COUNT(*) FROM VoteCount;

IF @@ERROR <> 0
BEGIN
    PRINT 'Error truncating tables in PollSys DB: Rolling back transaction...'
    ROLLBACK TRAN ClearData;
END
ELSE
BEGIN
    PRINT 'All tables truncated successfully: Committing transaction...'
    COMMIT TRAN ClearData;
END

-- Query #5: Fetch a report on the top 2 candidates with the most votes

USE [PollSysUnited]
GO

SELECT TOP 2 CONCAT(c.FirstName, ' ', c.LastName) AS [Name], 
	c.PartyRep AS [Political Party], 
	COUNT(vc.CandidateID) AS [# of votes]
FROM Candidates c
JOIN VoteCount vc ON c.CandidateID = vc.CandidateID
GROUP BY c.CandidateID, c.FirstName, c.LastName, c.PartyRep
ORDER BY COUNT(vc.CandidateID) DESC;

-- Query #6: Display the candidate who had the least votes

USE [PollSysUnited]

SELECT TOP 1 CONCAT(c.FirstName, ' ', c.LastName) AS [Name], 
	c.PartyRep AS [Political Party], 
	COUNT(vc.CandidateID) AS [# of votes]
FROM Candidates c
JOIN VoteCount vc ON c.CandidateID = vc.CandidateID
GROUP BY c.CandidateID, c.FirstName, c.LastName, c.PartyRep
ORDER BY COUNT(vc.CandidateID) ASC;

-- Query #7: Display candidates who recieved anywhere between 5 - 15 votes

USE [PollSysUnited]
GO

SELECT CONCAT(c.FirstName, ' ', c.LastName) AS [Name], 
	c.PartyRep AS [Political Party], 
	COUNT(vc.CandidateID) AS [# of votes]
FROM Candidates c
JOIN VoteCount vc ON c.CandidateID = vc.CandidateID
GROUP BY c.CandidateID, c.FirstName, c.LastName, c.PartyRep
HAVING COUNT(vc.CandidateID) >= 5 AND COUNT(vc.CandidateID) <= 15
ORDER BY COUNT(vc.CandidateID) DESC;

-- Query #8: Display all candidates final voting tallies

USE [PollSysUnited]
GO

SELECT CONCAT(c.FirstName, ' ', c.LastName) AS [Name], 
	c.PartyRep AS [Political Party], 
	COUNT(vc.CandidateID) AS [# of votes]
FROM Candidates c
JOIN VoteCount vc ON c.CandidateID = vc.CandidateID
GROUP BY c.CandidateID, c.FirstName, c.LastName, c.PartyRep
ORDER BY COUNT(vc.CandidateID) DESC;

-- Query #9: Display the winning candidates name

USE [PollSysUnited]
GO

SELECT TOP 1 CONCAT(c.FirstName, ' ', c.LastName) AS [Winning Candidate]
FROM Candidates c
JOIN VoteCount vc ON c.CandidateID = vc.CandidateID
GROUP BY c.CandidateID, c.FirstName, c.LastName, c.PartyRep
ORDER BY COUNT(vc.CandidateID) DESC;