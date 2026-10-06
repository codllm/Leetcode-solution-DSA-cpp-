class Solution {
private:
    int maxRecfunction(vector<int>& heights)
    {
        int n = heights.size();

        vector<int> rightSmaller(n, n);
        vector<int> leftSmaller(n, -1);

        stack<int> st;

        // Next smaller element on RIGHT
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                rightSmaller[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        while(!st.empty())
            st.pop();

        // Next smaller element on LEFT
        for(int i = n - 1; i >= 0; i--)
        {
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                leftSmaller[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        int maxRec = 0;

        for(int i = 0; i < n; i++)
        {
            int width = rightSmaller[i] - leftSmaller[i] - 1;

            int area = heights[i] * width;

            maxRec = max(maxRec, area);
        }

        return maxRec;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        if(matrix.empty() || matrix[0].empty())
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);

        int ans = 0;

        for(int i = 0; i < rows; i++)
        {
            // Build histogram for current row
            for(int j = 0; j < cols; j++)
            {
                if(matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            // Largest rectangle in current histogram
            ans = max(ans, maxRecfunction(heights));
        }

        return ans;
    }
};