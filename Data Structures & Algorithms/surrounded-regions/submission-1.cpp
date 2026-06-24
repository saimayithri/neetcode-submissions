class Solution {
public:
    void dfs(vector<vector<char>>& board, int r, int c) {


        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c]=='*'|| board[r][c]=='X')
        {
            return;
        }

        if(board[r][c]=='O')
        {
            board[r][c]='*';
        }
        dfs(board,r+1,c);
        dfs(board,r,c+1);
        dfs(board,r,c-1);
        dfs(board,r-1,c);

    }

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if(rows == 0) return;
        int cols = board[0].size();
        for(int i=0;i<rows;i++)
        {
            if(board[i][0]=='O') dfs(board,i,0);
            if(board[i][cols-1]=='O') dfs(board,i,cols-1);


        }

      
        for(int c = 0; c < cols; c++) {
            if(board[0][c] == 'O') dfs(board, 0, c);
            if(board[rows - 1][c] == 'O') dfs(board, rows - 1, c);
        }



        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
                if(board[i][j]=='*')
                {
                    board[i][j]='O';
                }
            }
        }
        
    }
};