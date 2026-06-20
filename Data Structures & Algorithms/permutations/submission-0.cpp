class Solution {
public:
    void backtrack(vector<int>& nums,vector<int>&current,vector<vector<int>>&result,vector<bool>&used){
            if(current.size()==nums.size())
            {   result.push_back(current);}

            for(int i=0;i<nums.size();i++)
            {
        
                if(used[i]==false){
                    current.push_back(nums[i]); used[i]=true;
                    backtrack(nums,current,result,used);
                    used[i]=false;  current.pop_back();                  
                }

            }
    }
    vector<vector<int>> permute(vector<int>& nums) {

        vector<int>current;
        vector<vector<int>> result;

        vector<bool> used(nums.size(),false);
        backtrack(nums,current,result,used);
        return result;


        
    }
};
