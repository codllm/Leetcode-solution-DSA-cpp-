class Solution {
    private:

    bool solve(vector<vector<char>>& board,string& word,int i,int j,int idx)
    {
        if(idx == word.size()) return true;

        if(i<0 || i>=board.size() || 
        j<0 || j>=board[0].size() ||
        board[i][j]!=word[idx]) return false;


        char temp = board[i][j];
        //apn is mein backtracking krna wale hai

        board[i][j] = '*';

        bool match = solve(board,word,i+1,j,idx+1) ||
        solve(board,word,i-1,j,idx+1) ||
        solve(board,word,i,j+1,idx+1) ||
        solve(board,word,i,j-1,idx+1);

        board[i][j] = temp;

        return match;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {


        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j] == word[0])
                {
                    //start searching
                    if(solve(board,word,i,j,0)) return true;
                }
            }
        }
        return false;
        
    }
};