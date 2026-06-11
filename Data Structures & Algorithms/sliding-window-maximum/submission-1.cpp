class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int>result;

        int l=0, r = k-1;
        while(r<nums.size())
        {
            int maxi=INT_MIN;
            for(int i=l;i<=r;i++)
            {
                maxi=max(maxi,nums[i]);
            }
            result.push_back(maxi);l++;r++;
        }
        return result;
        
    }
};
