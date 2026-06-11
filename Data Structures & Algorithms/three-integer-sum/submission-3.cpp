class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n=nums.size();
        vector<vector<int>> res; 
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i>0&&nums[i]==nums[i-1])
            {
                continue;
            }

            int l=i+1,r=n-1;
            while(l<r)
            {
                if (nums[l]+nums[r]==-nums[i])
                {
                    res.push_back({nums[l],nums[r],nums[i]});
                    l++;r--;

                        
                    while(l < r && nums[l] == nums[l - 1])
                    l++;

                    while(l < r && nums[r] == nums[r + 1])
                    r--;

                }
                else if (nums[l]+nums[r]<-nums[i])
                {
                    l++;

                }
                else 
                {
                    r--;

                }


            }
        }
        return res;
        
    }
};
