class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {

        //each row max value mil gya
        vector<int>maxRow;
        for(int i=0;i<grid.size();i++)
        {
            int max_val = *max_element(grid[i].begin(),grid[i].end());
            maxRow.push_back(max_val);
        }

        //each col ka maxm value mil gya
        vector<int>maxCol;
        for(int i=0;i<grid.size();i++)
        {
            int max_val = INT_MIN;
            for(int j=0;j<grid[0].size();j++)
            {
                max_val = max(max_val,grid[j][i]);
            }
            maxCol.push_back(max_val);
        }
        //calculate the now final answer
        int ans = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                int minh = min(maxRow[i],maxCol[j]);

                ans+=(minh-grid[i][j]);
            }
        }
        return ans;

        
    }
};