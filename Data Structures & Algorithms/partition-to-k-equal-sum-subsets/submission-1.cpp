class Solution {
private:
    bool dfs(vector<int>& matchsticks, vector<int>& sides, int index, int target, int k) {
 
        if(index==matchsticks.size())
        {
            return true;
        }

        for (int i = 0; i < k; i++) {

            if(sides[i]+matchsticks[index]>target)
            {
                continue;
            }
            sides[i] += matchsticks[index];
            

           if (dfs(matchsticks, sides, index + 1, target, k) == true) {
                return true; 
            }
            sides[i] -= matchsticks[index];

            if (sides[i] == 0) {
                break; 
            }
            
        }
        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(nums.size()<k){return false;}
        int sum=0;
        for(auto m: nums)
        {
            sum+=m;
        }
        if (sum % k != 0) return false;
        int target=sum/k; 

         
        sort(nums.rbegin(), nums.rend());
        vector<int> buckets(k,0);
        return dfs(nums,buckets,0,target,k);

    }
};