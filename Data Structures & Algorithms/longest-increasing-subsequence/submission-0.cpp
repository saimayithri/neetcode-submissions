class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0){return 0;}
        if(n==1){return 1;}

        vector<int>dp(n+1,1);

        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                }

            }
        }
        int ans= *max_element(dp.begin(),dp.end());
        return ans;
    }
};
