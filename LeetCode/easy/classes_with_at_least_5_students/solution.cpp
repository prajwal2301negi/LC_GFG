// Problem: Classes With at Least 5 Students
// Difficulty: easy
// Runtime: 323 ms
// Memory: 0.0B

SELECT class
FROM Courses
GROUP BY class
HAVING COUNT(student) >= 5;