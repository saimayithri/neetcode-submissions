class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

       unordered_set<int> numSet(nums.begin(), nums.end());
       int start =0;

        for(int num : nums) {
            // Only start counting if num is the beginning of a sequence
            if(numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int length = 1;

                // Count consecutive numbers
                while(numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    length++;
                }

                // Update max length
                start = max(start, length);
            }
        }

        return start;
    }
};
