// Problem: Customer Who Visited but Did Not Make Any Transactions
// Difficulty: easy
// Runtime: 1370 ms
// Memory: 0.0B

SELECT customer_id, COUNT(v.visit_id) as count_no_trans 
FROM Visits v
LEFT JOIN Transactions t ON v.visit_id = t.visit_id
WHERE transaction_id IS NULL
GROUP BY customer_id