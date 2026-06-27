class Solution {
class UnionFind {
private:
    vector<int> parent;
public:

    UnionFind(int n) {
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
     
        return parent[x] = find(parent[x]); 
    }
 
    bool unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) {
            return false;
        }
        
        parent[rootY] = rootX; 
        return true;
    }
};

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf(edges.size());
        
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
           
            if (uf.unionSet(u, v) == false) {
                return {u, v};
            }
        }
        return {};
    }
};
