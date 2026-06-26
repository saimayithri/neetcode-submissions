class Solution {
public:
    bool dfs(int node, int parent, vector<bool> &visited, vector<vector<int>> &adj ){
        visited[node]=true;

        for(int neighbor: adj[node])
        {
            if(!visited[neighbor])
            {
                if(dfs(neighbor,node,visited,adj)==false)
                    return false;
            }
            else if(neighbor != parent)
            {
                return false;
            }
        }
        return true;

        

    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;
        vector<vector<int>>adj(n);

        for(auto &edge: edges)
        {
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        vector<bool> visited(n,false);

        if (dfs(0,-1,visited,adj)==false){
            return false;
        }

        for(int i=0;i<n;i++)
        {
            if(!visited[i]) return false;
        }
        return true;

    }
};
