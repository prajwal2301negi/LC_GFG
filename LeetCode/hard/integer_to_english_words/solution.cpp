// Problem: Integer to English Words
// Difficulty: hard
// Runtime: 4 ms
// Memory: 10.5 MB

class Solution {
public:
    vector<string> belowTen = {"",     "One", "Two",   "Three", "Four",
                               "Five", "Six", "Seven", "Eight", "Nine"};

    vector<string> belowTwenty = {"Ten",      "Eleven",  "Twelve",  "Thirteen",
                                  "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                                  "Eighteen", "Nineteen"};

    vector<string> belowHundred = {"",       "",      "Twenty", "Thirty",
                                   "Forty",  "Fifty", "Sixty",  "Seventy",
                                   "Eighty", "Ninety"};

    string solve(int num) {

        // 0 - 9
        if (num < 10) {
            return belowTen[num];
        }

        // 10 - 19
        if (num < 20) {
            return belowTwenty[num - 10];
        }

        // 20 - 99
        if (num < 100) {

            string tensWord = belowHundred[num / 10];
            string onesWord = belowTen[num % 10];

            if (num % 10 == 0)
                return tensWord;

            return tensWord + " " + onesWord;
        }

        // 100 - 999
        if (num < 1000) {

            string hundredWord = belowTen[num / 100] + " Hundred";

            if (num % 100 == 0)
                return hundredWord;

            return hundredWord + " " + solve(num % 100);
        }

        // 1,000 - 999,999
        if (num < 1000000) {

            string thousandWord = solve(num / 1000) + " Thousand";

            if (num % 1000 == 0)
                return thousandWord;

            return thousandWord + " " + solve(num % 1000);
        }

        // 1,000,000 - 999,999,999
        if (num < 1000000000) {

            string millionWord = solve(num / 1000000) + " Million";

            if (num % 1000000 == 0)
                return millionWord;

            return millionWord + " " + solve(num % 1000000);
        }

        // Billion
        string billionWord = solve(num / 1000000000) + " Billion";

        if (num % 1000000000 == 0)
            return billionWord;

        return billionWord + " " + solve(num % 1000000000);
    }

    string numberToWords(int num) {

        if (num == 0)
            return "Zero";

        return solve(num);
    }
};