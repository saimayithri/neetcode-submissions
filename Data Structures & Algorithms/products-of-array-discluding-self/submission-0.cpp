class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> res(nums.size());

        for(int i=0;i<nums.size();i++)
        {
            int prod=1;
            for(int j=i+1;j<nums.size();j++)
            {
                prod*=nums[j];


            }
            for(int k=i-1;k>=0;k--)
            {
                prod*=nums[k];
            }
            res[i]=prod;
        }
        return res;

    }
};
