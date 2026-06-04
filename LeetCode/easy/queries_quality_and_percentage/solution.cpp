// Problem: Queries Quality and Percentage
// Difficulty: easy
// Runtime: 396 ms
// Memory: 0.0B

# Write your MySQL query statement below
select query_name,round(sum(rating/position)/count(*),2)as quality,
round(100*sum(rating<3)/count(*),2) as poor_query_percentage
from Queries group by query_name;