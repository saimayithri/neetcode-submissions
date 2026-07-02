class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        
        //[prev1,prev2,curr....] window
        int prev1=nums[0]; int prev2=max(prev1,nums[1]);
        for(int i=2;i<n;i++){
            //dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
            int curr= max(nums[i]+prev1,prev2);
            prev1=prev2;
            prev2=curr;
        }
        return prev2;
    }
};
