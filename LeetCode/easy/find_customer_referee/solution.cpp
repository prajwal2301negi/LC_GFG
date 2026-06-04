// Problem: Find Customer Referee
// Difficulty: easy
// Runtime: 465 ms
// Memory: 0.0B

# Write your MySQL query statement below
select name from customer where referee_id != 2 or referee_id is null;