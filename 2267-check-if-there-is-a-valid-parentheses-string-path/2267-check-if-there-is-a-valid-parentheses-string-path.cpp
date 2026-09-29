class Solution {
    int memo[105][105][205];
    private:
    bool solve(vector<vector<char>>& grid,int i,int j,int r,int c,int balanced)
    {
        if(i<0 || i>=r || j<0 || j>=c) return false;

        balanced+=(grid[i][j]=='(') ? 1: -1;

        if (balanced < 0)
            return false;
        if(i==r-1 && j==c-1)
        {
            return balanced==0;
        }
        //if any time i found this it means that then no need for further checking it
        if (memo[i][j][balanced] != -1) {
            return memo[i][j][balanced];
        }

        bool right = solve(grid,i,j+1,r,c,balanced);
        bool down = solve(grid,i+1,j,r,c,balanced);

        return memo[i][j][balanced] = (right || down);
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {

        int r = grid.size();
        int c = grid[0].size();
        memset(memo, -1, sizeof(memo));
        int balanced = 0;
        return solve(grid,0,0,r,c,balanced);
        
    }
};