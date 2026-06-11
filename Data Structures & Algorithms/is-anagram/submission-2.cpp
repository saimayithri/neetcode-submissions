class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size()!=t.size())
            {return false;}
        
        unordered_map <char,int> freqS, freqT;

        for(char c: s)
        {
            freqS[c]++;
        }
         for(char c: t)
        {
            freqT[c]++;
        }

        return freqS==freqT;

        


        
    }
};
