class Solution {
private:
    bool dfs(vector<int>& matchsticks, vector<int>& sides, int index, int target) {
        // 1. Base case: Did we place all matchsticks?
        if(index==matchsticks.size())
        {
            return true;
        }
        // 2. Loop through our 4 buckets (sides)
        for (int i = 0; i < 4; i++) {
            // Check if adding the current matchstick exceeds the target
            if(sides[i]+matchsticks[index]>target)
            {
                continue;
            }
            sides[i] += matchsticks[index];
            
            // Put matchstick in the bucket
           if (dfs(matchsticks, sides, index + 1, target) == true) {
                return true; // We found a valid square! Pass the success up the chain.
            }

            // Recurse to the next matchstick (index + 1). If it returns true, return true!
            sides[i] -= matchsticks[index];

            // Backtrack: Remove the matchstick from the bucket
            
        }
        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        // 1. Edge cases (size < 4)
        if(matchsticks.size()<4){return false;}
        int sum=0;
        for(auto m: matchsticks)
        {
            sum+=m;
        }
        if (sum % 4 != 0) return false;
        int target=sum/4; 
        // 2. Calculate sum, check modulo, find target
        
        // 3. Sort matchsticks in DESCENDING order (Golden Optimization)
         
        sort(matchsticks.rbegin(), matchsticks.rend());
        vector<int> sides(4,0);
        return dfs(matchsticks,sides,0,target);
        // 4. Initialize sides vector and call DFS
    }
};