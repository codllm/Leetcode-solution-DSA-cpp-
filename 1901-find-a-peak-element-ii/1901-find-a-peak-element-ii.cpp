class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int left = 0;
        int right = mat[0].size()-1;

        while(left<=right)
        {
            int mid = left+(right-left)/2;//mid act like my col

            int maxrow = 0;//in whcih row it has the greater val of hole col??coz that is only may possible answer in hole row no other than that
            //coz arround them all smaller

            for(int i=0;i<mat.size();i++)
            {
                if(mat[maxrow][mid]<mat[i][mid])
                {
                    maxrow = i;
                }
            }

            //col mein sbse bada value toh mil gya
            //ab uska left right check kro konsa value hai

            int leftval = (mid > 0) ? mat[maxrow][mid-1] : -1;
            int rightval = (mid < mat[0].size()-1) ? mat[maxrow][mid+1] : -1;

            int midval = mat[maxrow][mid];
            //alredy humein us row ka sbse bada ko use kiya hai toh noo need to check up and down
            //just check for left n right
            if(leftval < midval && midval > rightval) return {maxrow,mid};

            else if(midval<rightval) left=mid+1;
            else right = mid-1;
        }

        return {-1,-1};
        
    }
};