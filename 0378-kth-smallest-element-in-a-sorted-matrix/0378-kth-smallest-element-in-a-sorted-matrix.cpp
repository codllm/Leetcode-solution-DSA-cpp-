class Solution {
    private:
    int isCountLessThan(vector<vector<int>>& matrix,int mid)
    {
        int n=matrix.size()-1;
        int row = n;
        int col = 0;
        int count = 0;
        while(row>=0 && col<=n)
        {
            if(matrix[row][col]>mid)
            {
                row--;
            }
            else
            {
                count=count+row+1;
                col++;
            }
        }
        return count;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        //really accha tha question
        
        int n = matrix.size();

        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];

        while(left<right)
        {
            int mid = left+(right-left)/2;

            if(isCountLessThan(matrix,mid) < k)
            {
                left=mid+1;
            }
            else
            {
                right=mid;
            }
        }
        return left;
        
    }
};