class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c, int prevHeight) {

        if(r<0 || c<0 || r>=heights.size() || c>=heights[0].size() || visited[r][c] || heights[r][c]<prevHeight)
        {
            return;
        }
       
        visited[r][c]=true;
        dfs(heights,visited,r+1,c,heights[r][c]);
        dfs(heights,visited,r-1,c,heights[r][c]);
        dfs(heights,visited,r,c+1,heights[r][c]);
        dfs(heights,visited,r,c-1,heights[r][c]);

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        int rows = heights.size();
        if(rows == 0) return result;
        int cols = heights[0].size();

        vector<vector<bool>> pac(rows, vector<bool>(cols, false));
        vector<vector<bool>> atl(rows, vector<bool>(cols, false));

        for(int c = 0; c < cols; c++) {
           
            dfs(heights, pac, 0, c, heights[0][c]);
            
     
            dfs(heights, atl, rows - 1, c, heights[rows - 1][c]);
        }

        for(int r = 0; r < rows; r++) {
       
            dfs(heights, pac, r, 0, heights[r][0]);
      
            dfs(heights, atl, r, cols - 1, heights[r][cols - 1]);
        }
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                if(pac[r][c] && atl[r][c]){
                    result.push_back({r,c});
                }
            }
        }
    
        
        return result;
    }
};