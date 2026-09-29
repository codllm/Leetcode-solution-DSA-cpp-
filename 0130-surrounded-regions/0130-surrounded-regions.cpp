class Solution {
    private:
    void dfs(vector<vector<char>>& board,int i,int j,int r,int c)
    {
        if(i<0 || i>=r || j<0 || j>=c || board[i][j]=='X' || board[i][j]=='#') return;

        board[i][j] = '#';

        dfs(board,i+1,j,r,c);
        dfs(board,i-1,j,r,c);
        dfs(board,i,j+1,r,c);
        dfs(board,i,j-1,r,c);
    }
public:
    void solve(vector<vector<char>>& board) {


        if(board.empty() || board[0].empty()) return;
        int r = board.size();
        int c = board[0].size();

        //first row n last row
        for(int i=0;i<board[0].size();i++)
        {
            if(board[0][i]=='O')
            {
                dfs(board,0,i,r,c);
            }

            if(board[r-1][i]=='O')
            {
                dfs(board,r-1,i,r,c);
            }
        }

        for(int i=0;i<board.size();i++)
        {
            if(board[i][0]=='O') dfs(board,i,0,r,c);

            if(board[i][c-1]=='O') dfs(board,i,c-1,r,c);
        }

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]=='O')
                {
                    board[i][j] = 'X';
                }
                if(board[i][j]=='#')
                {
                    board[i][j]='O';
                }
            }
        }

        
    }
};