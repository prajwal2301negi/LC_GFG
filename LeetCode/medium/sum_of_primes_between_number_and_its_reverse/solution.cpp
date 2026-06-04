// Problem: Sum of Primes Between Number and Its Reverse
// Difficulty: medium
// Runtime: 35 ms
// Memory: 8.7 MB

class Solution {
public:
    int sumOfPrimesInRange(int n) {
        if(n == 1){
            return 0;
        }
        int r = reverseNum(n);
        
        int lowerBound = min(n,r);
        int upperBound = max(n, r);

        int sum = 0;
        
        if(lowerBound == 1) lowerBound++;
        for(int i = lowerBound ;i<=upperBound;i++){
            bool flag = true;
            
            for(int j = 2;j<i;j++){
                if(i%j == 0){
                    flag = false;
                    break;
                }
            }
            if(flag == true) sum+=i;
        }
        return sum;
    }

    int reverseNum(int n){
        int num = n;
        int rev = 0;
        while(num>0){
            int unitDigit = num%10;
            rev = rev*10 + unitDigit;
            num = num/10;
        }
        return rev;
    }
};