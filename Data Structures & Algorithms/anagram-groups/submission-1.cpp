class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map <string, vector<string>> check;

        string temp;

        for(int i=0; i<strs.size(); i++)
        {
            temp = strs[i];
            sort(temp.begin(), temp.end());
            check[temp].push_back(strs[i]);
        
        
        
        }
        vector<vector<string>> result;

        for (auto &pair:check)
        {
            result.push_back(pair.second);
        }
        return result;



 


        

        
        
    }
};
