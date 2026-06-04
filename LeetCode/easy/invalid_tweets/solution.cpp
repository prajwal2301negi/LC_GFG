// Problem: Invalid Tweets
// Difficulty: easy
// Runtime: 603 ms
// Memory: 0.0B

SELECT tweet_id FROM Tweets
WHERE LENGTH(content) > 15;