// Problem: Biggest Single Number
// Difficulty: easy
// Runtime: 458 ms
// Memory: 0.0B

# Write your MySQL query statement below
SELECT MAX(num) AS num
FROM MyNumbers
WHERE num IN (
    SELECT num
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(num) = 1
);