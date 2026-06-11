class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.length() > s2.length())
            return false;
        vector <char>s1check(26,0);vector <char>s2check(26,0);
        for(int i=0;i<s1.length();i++)
        {
            s1check[s1[i]-'a']++;
            s2check[s2[i]-'a']++;
        }

       
        if(s1check == s2check)
            return true;

        int l=0;
        
        for(int r=s1.length();r<s2.length();r++)
        {
            s2check[s2[r]-'a']++;

            s2check[s2[l]-'a']--;
            l++;
            if(s1check==s2check)
                return true;
            


        }
        return false;

        
    }
};
