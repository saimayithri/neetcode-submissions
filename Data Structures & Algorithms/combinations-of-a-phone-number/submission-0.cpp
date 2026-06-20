class Solution {
public:
    vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void backtrack(int index, string& digits,vector <string>& result,string &current ){
        if(current.size()==digits.size())
        {
            result.push_back(current);
            return;
        }
        int num= digits[index]-'0';

        for(int i=0;i<pad[num].size();i++)
        {
            current.push_back(pad[num][i]);
            backtrack(index+1,digits,result,current);
            current.pop_back();
        }

        
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
        {
            return {};
        }
        vector <string> result;
        string current ="";
        backtrack(0,digits,result,current);
        return result;

        
    }
};
