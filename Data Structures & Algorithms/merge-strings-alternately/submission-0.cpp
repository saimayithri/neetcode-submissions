class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int first=0, second=0; string ans = "";
      
        while(first<word1.size() || second<word2.size())
        {
            
            if(first<word1.size())
            {
                ans += word1[first];
                first++;
            }
            if(second<word2.size())
            {
                ans += word2[second];
                second++;
            }
            


        }
        return ans;
        
    }
};