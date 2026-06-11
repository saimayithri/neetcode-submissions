#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size()==0)
            return false;  // Correct usage of std::sort for vector

        for(int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true; // Found duplicate
            }
        }

        return false; // No duplicates found
    }
};
