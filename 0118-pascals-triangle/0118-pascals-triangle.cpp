class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>>pascaltri(numRows);

        for(int i=0;i<numRows;i++)
        {
            pascaltri[i] = vector<int>(i+1,1);
        }

        for(int i=0;i<pascaltri.size();i++)
        {
            for(int j=1;j<i;j++)
            {
                pascaltri[i][j] = pascaltri[i-1][j]+pascaltri[i-1][j-1];
            }
        }
        return pascaltri;
        
    }
};