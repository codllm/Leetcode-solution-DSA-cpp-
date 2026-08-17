class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {

        int countHowManynegative = 0;
        long long maxsum = 0;
        int mini = INT_MAX;

        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] < 0)
                    countHowManynegative++;

                maxsum += abs(matrix[i][j]);
                mini = min(mini, abs(matrix[i][j]));
            }
        }

        if(countHowManynegative % 2 == 0)
        {
            return maxsum;
        }
        else
        {
            return maxsum - 2LL * mini;
        }
    }
};