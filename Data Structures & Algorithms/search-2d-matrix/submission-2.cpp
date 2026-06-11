class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();        // number of rows
        int n = matrix[0].size();     // number of columns

        int low = 0, high = m * n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            // Convert 1D index to 2D: row = mid / n, col = mid % n
            int element = matrix[mid / n][mid % n];

            if (element == target) return true;
            else if (element < target) low = mid + 1;
            else high = mid - 1;
        }

        return false;
    }
};
