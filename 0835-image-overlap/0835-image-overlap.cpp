class Solution {
    int countOverlaps(vector<vector<int>>& A,
                      vector<vector<int>>& B,
                      int rowoffset,
                      int coloffset)
    {
        int cnt = 0;
        int n = A.size();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int B_i = i + rowoffset;
                int B_j = j + coloffset;

                if(B_i < 0 || B_i >= n || B_j < 0 || B_j >= n)
                    continue;

                if(A[i][j] == 1 && B[B_i][B_j] == 1)
                    cnt++;
            }
        }

        return cnt;
    }

public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {

        int n = A.size();
        int maxCnt = 0;

        for(int i = -(n-1); i < n; i++)
        {
            for(int j = -(n-1); j < n; j++)
            {
                int count = countOverlaps(A, B, i, j);

                maxCnt = max(maxCnt, count);
            }
        }

        return maxCnt;
    }
};