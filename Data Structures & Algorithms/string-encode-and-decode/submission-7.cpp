class Solution {
public:

    string encode(vector<string>& strs) {
        string encode="";
        for(string &s:strs)
        {
            encode+="["+to_string(s.size())+"]"+s;

        }
        return encode;

    }

    vector<string> decode(string s) {

        int i=0;vector<string> result;
        while(i<s.size())
        {
            if(s[i]=='[')
            {
                int j=i+1;
                while(s[j]!=']')
                {
                    j++;
                }
                int num = stoi(s.substr(i+1,j-i-1));
                result.push_back(s.substr(j+1,num));
                i=j+1+num;
            
            }
            else
                i++;
        }
        return result;
        
    }
};
