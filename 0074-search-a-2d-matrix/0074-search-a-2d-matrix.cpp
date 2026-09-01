class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row=matrix.size()-1;
        int col=matrix[0].size()-1;
        int i=0;
        int j=col;

        while(i<=row && j>=0)
        {
            if(matrix[i][j]==target) return true;

            if(matrix[i][j]<target)
            {
                i++;
            }
            else j--;
        }

        return false;
        
    }
};