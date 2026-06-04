// Problem: Rising Temperature
// Difficulty: easy
// Runtime: 374 ms
// Memory: 0.0B

SELECT current_day.id
FROM Weather AS current_day
WHERE EXISTS (
    SELECT 1
    FROM Weather AS yesterday
    WHERE current_day.temperature > yesterday.temperature
    AND current_day.recordDate = yesterday.recordDate + INTERVAL 1 DAY
);