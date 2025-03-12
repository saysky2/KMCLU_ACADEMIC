-- Write SQL queries using logical operator 

CREATE DATABASE IF NOT EXISTS LOGICAL_OPERATORS;

USE LOGICAL_OPERATORS;

 CREATE TABLE IF NOT EXISTS KMCLU_BTECH(
    RollNo INT PRIMARY KEY,
    FirstName VARCHAR(50),
    LastName VARCHAR(50),
    Department VARCHAR(50),
    Email VARCHAR(50)
);

INSERT INTO KMCLU_BTECH VALUES 
(8, "Akash", "Gupta", "AI&ML", "xyz@gmail.com"), 
(28, "Vaibhav", "Yadav", "CSE", "abc@gmail.com"), 
(51, "Alifarm", "Khan", "CIVIL", "pqs@gmail.com");

SELECT * FROM KMCLU_BTECH; -- showing all the data 

-- AND Operator
SELECT * FROM KMCLU_BTECH WHERE FirstNAME = 'ALIFARM' AND Department = 'CIVIL';

-- IR Operator