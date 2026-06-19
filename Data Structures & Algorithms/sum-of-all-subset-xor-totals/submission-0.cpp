class Solution {
public:
    void backTrack(int index,vector<int>& nums, int &totalSum, int sum ){
        totalSum+=sum;

        for(int i=index;i<nums.size();i++)
        {
            
            backTrack(i+1,nums,totalSum,sum^nums[i]);
        }
    }
    int subsetXORSum(vector<int>& nums) {
        int totalSum=0;
        backTrack(0,nums,totalSum,0);
        return totalSum;
        
    }
};