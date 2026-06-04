// Problem: Percentage of Users Attended a Contest
// Difficulty: easy
// Runtime: 1121 ms
// Memory: 0.0B

# Write your MySQL query statement below

SELECT 
    contest_id
    ,ROUND(COUNT(DISTINCT u.user_id)*100 / (SELECT COUNT(*) FROM users),2) AS percentage
FROM users u
JOIN register r
    ON u.user_id=r.user_id
GROUP BY r.contest_id
ORDER BY percentage DESC, r.contest_id ASC
