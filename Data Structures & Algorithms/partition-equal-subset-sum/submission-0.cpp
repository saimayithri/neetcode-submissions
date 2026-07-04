class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        // If the sum is odd, we can't split it evenly
        if (totalSum % 2 != 0) return false;
        
        int target = totalSum / 2;
        
        // Our "Checklist". False means no checkmark, True means checkmark.
        vector<bool> dp(target + 1, false);
        dp[0] = true; // We can always make sum 0
        
        // Pick up each number one by one
        for (int num : nums) {
            
            // Walk backwards through the checklist
            for (int i = target; i >= num; i--) {
                
                // If we could make the sum (i - num) before, 
                // we can now make the sum (i) by adding 'num' to it!
                if (dp[i - num] == true) {
                    dp[i] = true;
                }
            }
        }
        
        // Does the target have a checkmark?
        return dp[target]; 
    }
};