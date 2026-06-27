class Solution {
public:
    bool dfs(int node, vector<vector<int>>&adj,vector<int>&state){
        if(state[node]==1){return false;}
        if(state[node]==2){return true;}

        state[node]=1;

        for(auto neighbour: adj[node])
        {
            if(dfs(neighbour,adj,state)==false){return false;}

        }
        state[node]=2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto &edge: prerequisites){
            int a = edge[0];
            int b = edge[1];
            adj[b].push_back(a);
        }
        vector<int>state(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(state[i]==0){
                if(dfs(i,adj,state)==false)
                {   return false;
                }
            }
        }
        return true;
        
    }
};
