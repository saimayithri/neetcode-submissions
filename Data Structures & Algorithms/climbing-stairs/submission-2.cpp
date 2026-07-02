class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        int step1 = 1; 
        int step2 = 2;
        
        for (int i = 3; i <= n; i++) {
            int temp = step1 + step2;
            step1 = step2;
            step2 = temp;
        }
        return step2;
    }
};