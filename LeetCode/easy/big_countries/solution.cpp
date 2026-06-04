// Problem: Big Countries
// Difficulty: easy
// Runtime: 279 ms
// Memory: 0.0B

# Write your MySQL query statement below

select name, population, area from World where area >=3000000 or population>=25000000;