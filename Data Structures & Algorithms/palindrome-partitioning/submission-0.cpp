class Solution {
public:
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    void backtrack(string &s, int index,vector<vector<string>>&result, vector<string>&current ){
        if(index==s.length()){result.push_back(current); return;}

        for(int i=index;i<s.length();i++)
        {
            if(isPalindrome(s,index,i )){
                current.push_back(s.substr(index, i - index + 1));
                backtrack(s,i +1,result,current);
                current.pop_back();
            }
                
            
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;   
        backtrack(s,0,result,current);
        return result;    
    }
};
