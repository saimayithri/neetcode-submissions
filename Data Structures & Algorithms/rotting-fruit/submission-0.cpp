class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int,int>>q; int freshc=0;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if (grid[i][j]==2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                {
                    freshc++;
                }
            }
        }

        int mins=0;

        while(!q.empty()&&freshc>0)
        {
            int num = q.size();

            for(int i=0;i<num;i++)
            {
                int r=q.front().first;
                int c=q.front().second; q.pop();


                if(r-1>=0 && grid[r-1][c]==1){ 
                    grid[r-1][c]=2;
                    freshc--;
                    q.push({r-1,c});
                }
                if(c-1>=0 && grid[r][c-1]==1){ 
                    grid[r][c-1]=2;
                    freshc--;
                    q.push({r,c-1});
                }
                if(r+1< grid.size() && grid[r+1][c]==1){ 
                    grid[r+1][c]=2;
                    freshc--;
                    q.push({r+1,c});
                }
                if(c+1< grid[0].size() &&grid[r][c+1]==1){ 
                    grid[r][c+1]=2;
                    freshc--;
                    q.push({r,c+1});
                }
                
                
            }
            mins++;
        }
        if(freshc==0)
        {
            return mins;
        }
        else
        {
            return -1;
        }
        
    }
};
