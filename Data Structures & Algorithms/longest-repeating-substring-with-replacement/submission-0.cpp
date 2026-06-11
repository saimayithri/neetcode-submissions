class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        int maxLen = 0;
        int maxFreq = 0;
        unordered_map<char, int> freq;

        while (right < s.size()) {  // ✅ Fix 1: should be right < s.size()
            freq[s[right]]++;
            maxFreq = max(maxFreq, freq[s[right]]);

            // ✅ Check if more than k characters need to be replaced
            if ((right - left + 1) - maxFreq > k) {
                freq[s[left]]--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};
