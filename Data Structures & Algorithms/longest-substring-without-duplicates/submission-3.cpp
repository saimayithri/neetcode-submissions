class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<int> window;
        int l=0; int maxseq=0;

        for(int r=0;r<s.length();r++)
        {
            
            while(window.count(s[r]))
            {
                window.erase(s[l]);l++;


            }
            
            
            window.insert(s[r]);
            maxseq=max(maxseq,(r-l+1));


        }
        return maxseq;
        
    }
};
