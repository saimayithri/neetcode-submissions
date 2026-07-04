class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        int n=s.length();
        for(auto s:wordDict){
            dict.insert(s);
        }
        vector<bool> dp(n + 1, false);
        dp[0]=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[j]==true && dict.find(s.substr(j,i-j))!= dict.end()){
                    dp[i]=true; break;
                }
            }
        }
        return dp[n];
        
    }
};
