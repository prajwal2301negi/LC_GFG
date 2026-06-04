// Problem: Employee Bonus
// Difficulty: easy
// Runtime: 1213 ms
// Memory: 0.0B

SELECT e.name, b.bonus FROM Employee e
LEFT JOIN Bonus b
ON e.empId = b.empId
WHERE b.bonus IS NULL OR b.bonus < 1000;