class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) return 0; // Edge case: 0 or 1 interval means 0 removals
        
        // Step 1: Sort by start time
        sort(intervals.begin(), intervals.end());
        
        int count = 0;
        int prevEnd = intervals[0][1];
        
        // Step 2: Iterate and greedily remove the interval that ends later
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= prevEnd) {
                // NO OVERLAP: Update prevEnd to the current interval's end
                prevEnd = intervals[i][1];
            } else {
                // OVERLAP: We must remove one. 
                count++;
                // GREEDY CHOICE: Keep the one that ends EARLIER to leave more room
                prevEnd = min(prevEnd, intervals[i][1]);
            }
        }
        
        return count;
    }
};