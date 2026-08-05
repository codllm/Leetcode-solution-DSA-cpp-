class Solution {
private:

    bool issafe(vector<string>& board, int row, int col, int n)
    {
        // col 
        for(int i = 0; i < row; i++)
        {
            if(board[i][col] == 'Q') return false;
        }

        int i = row;
        int j = col;

        while(i >= 0 && j >= 0)
        {
            if(board[i][j] == 'Q')
                return false;

            i--;
            j--;
        }

        // upper 
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

    void solve(int row,
               int n,
               vector<string>& board,
               vector<vector<string>>& result)
    {
        // all queens placed
        if(row == n)
        {
            result.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++)
        {
            if(issafe(board, row, col, n))
            {
                board[row][col] = 'Q';

                solve(row + 1, n, board, result);

                // backtrack
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        vector<vector<string>> result;

        solve(0, n, board, result);

        return result;
    }
};