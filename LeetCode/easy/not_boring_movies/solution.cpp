// Problem: Not Boring Movies
// Difficulty: easy
// Runtime: 260 ms
// Memory: 0.0B

# Write your MySQL query statement below

SELECT *
FROM cinema c
WHERE c.id % 2 =1 
    AND 
    c.description != 'boring'
ORDER BY c.rating DESC;