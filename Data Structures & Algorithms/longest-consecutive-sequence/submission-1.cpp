class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int maxCount = 0;

        for (int num : s) {
            if (s.count(num - 1))
                continue;

            int curr = num;
            int count = 1;

            while (s.count(curr + 1)) {
                curr++;
                count++;
            }

            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};