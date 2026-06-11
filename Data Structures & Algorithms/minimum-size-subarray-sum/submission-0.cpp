class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int l=0;int minseq=INT_MAX;int sum=0;

        for(int r=0;r<nums.size();r++)
        {
            sum+=nums[r];
            
            
            while(sum>=target)
            {
                minseq=min(minseq,r-l+1);
                sum-=nums[l];l++;
            }
            

        }
        return minseq == INT_MAX ? 0 : minseq;
        
    }
};