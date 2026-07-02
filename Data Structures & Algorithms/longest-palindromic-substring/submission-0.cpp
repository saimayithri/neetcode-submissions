class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0;  // Where our best palindrome begins
        int maxLen = 0; // How long it is
        
        for (int i = 0; i < s.length(); i++) {
            // TODO 1: Call helper for ODD length palindrome (center is i)
            int len1 = expandAroundCenter(s, i, i);
            
            // TODO 2: Call helper for EVEN length palindrome (center is i and i+1)
            int len2 = expandAroundCenter(s, i, i+1);
            
            // Take the max of both attempts
            int currentMax = max(len1, len2);
            
            // If we found a new longest palindrome, update maxLen and start!
            if (currentMax > maxLen) {
                maxLen = currentMax;
                // We use i (the center) to calculate where the string actually starts
                start = i - (currentMax - 1) / 2; 
            }
        }
        
        // s.substr(starting_index, length)
        return s.substr(start, maxLen);
    }
    
private:
    int expandAroundCenter(const string& s, int left, int right) {
        // TODO 3: Write the while loop to expand outwards.
        // It should keep running as long as:
        // 1. left is not out of bounds
        // 2. right is not out of bounds
        // 3. the characters at left and right match
        while(left>=0&&right<s.length()&& s[left]==s[right])
        {
            left--;right++;
        }
        
        // By the time the while loop breaks, left and right have gone ONE step too far.
        // E.g., if palindrome is from index 1 to 3, left ended up at 0, and right ended up at 4.
        // What is the math formula to return the true length? 
        return ((right-1)-(left+1)+1); /* ??? */;
    }
};