class Solution {
public:

    bool win(vector<string>& board, char ch)
    {
        // Top row
        if(board[0][0] == ch &&
           board[0][1] == ch &&
           board[0][2] == ch)
            return true;

        // Middle row
        else if(board[1][0] == ch &&
                board[1][1] == ch &&
                board[1][2] == ch)
            return true;

        // Bottom row
        else if(board[2][0] == ch &&
                board[2][1] == ch &&
                board[2][2] == ch)
            return true;

        // Left column
        else if(board[0][0] == ch &&
                board[1][0] == ch &&
                board[2][0] == ch)
            return true;

        // Middle column
        else if(board[0][1] == ch &&
                board[1][1] == ch &&
                board[2][1] == ch)
            return true;

        // Right column
        else if(board[0][2] == ch &&
                board[1][2] == ch &&
                board[2][2] == ch)
            return true;

        // Main diagonal
        else if(board[0][0] == ch &&
                board[1][1] == ch &&
                board[2][2] == ch)
            return true;

        // Anti-diagonal
        else if(board[0][2] == ch &&
                board[1][1] == ch &&
                board[2][0] == ch)
            return true;

        return false;
    }

    bool validTicTacToe(vector<string>& board) {

        int xcount = 0;
        int ocount = 0;

        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == 'X')
                    xcount++;

                else if(board[i][j] == 'O')
                    ocount++;
            }
        }

        // Invalid move
        if(ocount > xcount)
            return false;

        if(xcount != ocount && xcount != ocount + 1)
            return false;

        bool xWin = win(board, 'X');
        bool oWin = win(board, 'O');

        // Both cannot win
        if(xWin && oWin)
            return false;

        // X wins
        if(xWin)
        {
            if(xcount != ocount + 1)
                return false;
        }

        // O wins
        if(oWin)
        {
            if(xcount != ocount)
                return false;
        }

        return true;
    }
};