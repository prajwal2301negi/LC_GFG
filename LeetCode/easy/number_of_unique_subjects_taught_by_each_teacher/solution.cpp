// Problem: Number of Unique Subjects Taught by Each Teacher
// Difficulty: easy
// Runtime: 519 ms
// Memory: 0.0B

# Write your MySQL query statement below
Select  teacher_id ,
count(distinct subject_id ) as cnt from Teacher
group by teacher_id