class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        int i = row-1;
        int j = 0;
        int ans = 0;
        while(i>=0 && j<col)
        {
            if(grid[i][j]<0)
            {
                //if one smaller found if may possible that more smaller left up side to right side all smaller than that so i keep on adding (col-j) all those will be part of mine answer
                ans = ans + col-j;
                i--;
                
            }
            //if i found grater number then smaller lie left-side only so move left now          
            else j++;

        }
        return ans;
        
    }
};