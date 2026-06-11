class Solution {
public:
    int characterReplacement(string s, int k) {

        int l=0; int maxseq=0; unordered_map<char,int>freq;int maxFreq=0;

        for(int r=0;r<s.length();r++)
        {
           freq[s[r]]++;
           maxFreq=max(maxFreq,freq[s[r]]);

           while((r-l+1)-maxFreq>k)
           {
                freq[s[l]]--;l++;
           }
           maxseq=max(r-l+1,maxseq);


        }
        return maxseq;


        
    }
};
