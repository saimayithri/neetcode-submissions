class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==0){return 0;}
        if(n==1){return nums[0];}

        int currMax=nums[0];
        int currMin=nums[0];
        int ans = nums[0];
        for(int i=1;i<n;i++)
        {
            int tempMax=max({nums[i],nums[i]*currMax,nums[i]*currMin});
            currMin=min({nums[i],nums[i]*currMax,nums[i]*currMin});
            currMax=tempMax;
            ans = max(ans, currMax);
        }
        return ans;

        
    }
};
