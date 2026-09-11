class Solution {
private:
    set<int> st;

    void solve(vector<int>& digits, int num, vector<bool>& visited)
    {
        string nums = to_string(num);

        if (nums.size() == 3)
        {
            if (num % 2 == 0)
            {
                st.insert(num);
            }
            return;
        }

        for (int i = 0; i < digits.size(); i++)
        {
            if (visited[i])
                continue;

            // No leading zero
            if (num == 0 && digits[i] == 0)
                continue;

            visited[i] = true;

            int oldnum = num;

            solve(digits, num * 10 + digits[i], visited);

            num = oldnum;       // backtrack
            visited[i] = false;
        }
    }

public:
    int totalNumbers(vector<int>& digits)
    {
        vector<bool> visited(digits.size(), false);

        solve(digits, 0, visited);

        return st.size();
    }
};