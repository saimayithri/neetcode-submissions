class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        unordered_map <int,int> mp; int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }

        vector<int>result;

        for(auto p: mp)
        {
            if(p.second>(n/3))
            {
                result.push_back(p.first);
            }

        }  
        return result;      
        
    }
};