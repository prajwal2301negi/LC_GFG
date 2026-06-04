// Problem: Replace Employee ID With The Unique Identifier
// Difficulty: easy
// Runtime: 1187 ms
// Memory: 0.0B

SELECT euni.unique_id, e.name 
FROM Employees e  
LEFT JOIN EmployeeUNI euni  
ON e.id = euni.id;