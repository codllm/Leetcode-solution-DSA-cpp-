class Solution {
public:
    vector<string> createGrid(int m, int n) {

        vector<string>grid(m,string(n,'#'));
        //form l shape
        // row = 0 fill with the '.'
        for(int i=0;i<n;i++)
        {
            grid[0][i]='.';
        }
        //col = last fil with the '.'

        for(int i=0;i<m;i++)
        {
            grid[i][n-1]='.';
        }
        return grid;

        

        
    }
};