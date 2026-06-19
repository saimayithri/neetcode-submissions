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
            if (i > index && nums[i] == nums[i - 1]) continue;
            current.push_back(nums[i]); 
            backTrack(i+1,nums,target,sum+=nums[i],current,result);

            current.pop_back();
            sum-=nums[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>result; vector<int>current;
        sort(candidates.begin(),candidates.end());
        backTrack(0,candidates,target,0,current,result);
        return result;
        
    }
};
