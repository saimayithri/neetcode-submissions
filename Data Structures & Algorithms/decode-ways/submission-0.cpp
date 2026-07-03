class Solution {
public:
    int numDecodings(string s) {
        // If it starts with '0', it's impossible to decode.
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        
        int n = s.length();
        // Initialize with 0s, not -1s, because we will be ADDING to them!
        vector<int> dp(n + 1, 0); 
        
        // Base cases
        dp[0] = 1; // The "invisible platform" so the 2-step works
        dp[1] = 1; // We already checked s[0] != '0', so length 1 is 1 way.
        
        for (int i = 2; i <= n; i++) {
            // Check 1-step (single digit)
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            
            // Check 2-step (double digit)
            // Use substring to grab the last 2 characters
            int twoDigit = stoi(s.substr(i - 2, 2)); 
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        
        return dp[n];
    }
};