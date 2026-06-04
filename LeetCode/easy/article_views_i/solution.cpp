// Problem: Article Views I
// Difficulty: easy
// Runtime: 396 ms
// Memory: 0.0B

# Write your MySQL query statement below

select distinct author_id as id from Views
where author_id = viewer_id 
order by id;