class Solution {
public:

    bool dfs(int node, vector<vector<int>>&adj, vector<int>&state, vector<int>& result){
        if(state[node]==1){return false;}
        if(state[node]==2){return true;}

        state[node]=1;

        for(auto neighbour: adj[node]) {
         
            if(dfs(neighbour, adj, state, result) == false) {
                return false; 
            }
        }
        
        state[node]=2;
        result.push_back(node); 
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> result;
        
        for(auto &edge: prerequisites){
            int a = edge[0];
            int b = edge[1];
            adj[b].push_back(a);
        }
        
        vector<int>state(numCourses,0);
        
        for(int i = 0; i < numCourses; i++) {
            if(state[i] == 0) {
      
                if(dfs(i, adj, state, result) == false) {
                    return {};
                }
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};