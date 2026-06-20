class Solution {
public:
    void backtrack(vector<int>& nums,vector<int>&current,vector<vector<int>>&result,vector<bool>&used){
            if(current.size()==nums.size())
            {   result.push_back(current); return;}

            for(int i=0;i<nums.size();i++)
            {
                if(i>0 && nums[i]==nums[i-1] && used[i-1]==false){continue;}
        
                if(used[i]==false){
                    current.push_back(nums[i]); used[i]=true;
                    backtrack(nums,current,result,used);
                    used[i]=false;  current.pop_back();                  
                }

            }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<int>current;
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(),false);
        backtrack(nums,current,result,used);
        return result;


        
    }
};
