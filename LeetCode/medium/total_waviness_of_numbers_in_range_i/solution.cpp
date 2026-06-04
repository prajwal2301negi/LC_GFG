// Problem: Total Waviness of Numbers in Range I
// Difficulty: medium
// Runtime: 44 ms
// Memory: 9.5 MB

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int cnt = 0;

        if (num1 < 100 and num2 < 100)
            return 0;
        if (num1 < 100 and num2 > 100)
            num1 = 101;

        if (num1 == num2) {
            string num = to_string(num1);
            for (int i = 1; i < num.size() - 1; i++) {
                int prev = num[i - 1] - '0';
                int curr = num[i] - '0';
                int next = num[i + 1] - '0';
                if (prev > curr and curr < next ||
                    (prev < curr and curr > next))
                    cnt++;
            }

            return cnt;
        }

        for (int i = num1; i <= num2; i++) {
            string num = to_string(i);
            int n = num.size();
            for (int i = 1; i < n - 1; i++) {
                int prev = num[i - 1] - '0';
                int curr = num[i] - '0';
                int next = num[i + 1] - '0';
                if (prev > curr and curr < next ||
                    (prev < curr and curr > next))
                    cnt++;
            }
        }
        return cnt;
    }
};