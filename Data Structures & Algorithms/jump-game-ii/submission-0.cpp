class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int current_level_end = 0; // The end of the "current level"
        int farthest_we_can_reach = 0; // The furthest index reachable in the "next level"

        // We walk through the array. 
        // We stop at n-1 because we don't need to jump FROM the last index.
        for (int i = 0; i < nums.size() - 1; i++) {
            
            // At every step, we see how far we COULD go in the NEXT level
            farthest_we_can_reach = max(farthest_we_can_reach, i + nums[i]);

            // If we have finished exploring everything in our "current level"...
            if (i == current_level_end) {
                jumps++; // ...we MUST take a jump to enter the next level
                current_level_end = farthest_we_can_reach; // Our level now extends to the farthest point we found
            }
        }
        
        return jumps;
    }
};