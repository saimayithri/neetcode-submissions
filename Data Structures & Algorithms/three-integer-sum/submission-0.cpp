class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        
        vector<vector<int>> result;

        for(int i=0;i<nums.size()-2;i++)
        {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j=i+1;int k=nums.size()-1;
            int target=-nums[i];
            while(j<k)
            {   if(nums[j]+nums[k]==target)
                {
                    result.push_back({nums[i],nums[j],nums[k]});
                    j++;k--;
                    while (j < k && nums[j] == nums[j-1]) j++; //  skip duplicate j
                    while (j < k && nums[k] == nums[k+1]) k--; //  skip duplicate k

                }
                else if(nums[j]+nums[k]>target)
                {
                    k--;
                }
                else if(nums[j]+nums[k]<target)
                {
                    j++;
                }
            }


        



        }
        return result;
        
    }
};
