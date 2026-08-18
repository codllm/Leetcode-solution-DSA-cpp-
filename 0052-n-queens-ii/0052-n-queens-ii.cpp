class Solution {
    int ans = 0;
    private:
    bool isvalid(int n, int row, int col, vector<vector<char>>& board)
{
    // column
    for(int i = 0; i < row; i++)
    {
        if(board[i][col] == 'Q')
            return false;
    }

    // upper-left diagonal
    int i = row;
    int j = col;
    while(i >= 0 && j >= 0)
    {
        if(board[i][j] == 'Q')
            return false;
        i--;
        j--;
    }

    // upper-right diagonal
    i = row;
    j = col;
    while(i >= 0 && j < n)
    {
        if(board[i][j] == 'Q')
            return false;
        i--;
        j++;
    }

    return true;
}
    void solve(int n,vector<vector<char>>& board,int row)
    {
        if(row == n)
        {
            ans++;
            return;
        }

        for(int col=0;col<n;col++)
        {
            if(isvalid(n,row,col,board))
            {
                board[row][col] = 'Q';

                solve(n,board,row+1);

                //backtrack

                board[row][col] = '.';
            }
        }
    }
public:
    int totalNQueens(int n) {

        vector<vector<char>>board(n,vector<char>(n,'.'));

        solve(n,board,0);
        return ans;
        
    }
};