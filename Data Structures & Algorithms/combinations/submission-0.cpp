class Solution {
public:
    void backTrack(int index, int n, int k, vector <int> &current, vector<vector<int>>&result ){
        if(current.size()==k)
        {
            result.push_back(current); return;
        }
        for(int i=index;i<=n;i++)
        {
            if(current.size()<k){current.push_back(i);}
            backTrack(i+1,n,k,current,result);
            current.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
       vector <int> current; vector<vector<int>>result;
       backTrack(1,n,k,current,result);
       return result; 
        
    }
};