class Solution {
public:
    void backTrack(int index, vector<int>& nums, int target, int sum, vector <int> &current, vector<vector<int>> & result){
        if(sum==target)
        {
            result.push_back(current);
            return;
        }
        if(sum>target) return;
        for(int i=index;i<nums.size();i++)
        {
            current.push_back(nums[i]); sum+=nums[i];
            backTrack(i,nums,target,sum,current,result);

            current.pop_back();
            sum-=nums[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>result; vector<int>current;
      
        backTrack(0,nums,target,0,current,result);
        return result;
        
    }
};
