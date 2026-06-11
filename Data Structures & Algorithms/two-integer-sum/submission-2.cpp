class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {

        unordered_map <int,int> sum;
        int difference=0;

        for(int i=0; i<nums.size();i++)
        {
            difference=target-nums[i];
            if(sum.find(difference)!=sum.end())
            {
                return {sum[difference],i};
            }
            sum[nums[i]]=i;


        }
        return {};
        
    }
};
