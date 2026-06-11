class Solution {
public:
    int search(vector<int>& nums, int target) {

        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {

            int mid = l + (r - l) / 2;  // Overflow-safe

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                l = mid + 1;    // Search right half
            }
            else {
                r = mid - 1;    // Search left half
            }
        }

        return -1;
    }
};