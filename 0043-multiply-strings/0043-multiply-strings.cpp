class Solution {
public:
    string multiply(string num1, string num2) {

        if (num1 == "0" || num2 == "0")
            return "0";

        int n = num1.size();
        int m = num2.size();

        vector<int> result(n + m, 0);

        // traverse across num1 one by one from back-side
        for (int i = n - 1; i >= 0; i--) {

            // traverse across num2 of each of num1 with all num2
            for (int j = m - 1; j >= 0; j--) {

                int a = num1[i] - '0';
                int b = num2[j] - '0';

                int c = a * b;

                // store the filling start-position
                int k = i + j + 1;

                // add previous value also
                int sum = result[k] + c;

                // fill the last digit (base)
                result[k] = sum % 10;

                // carry goes to previous position
                result[k - 1] += sum / 10;
            }
        }

        string ans = "";

        // skip leading zeros
        int i = 0;
        while (i < result.size() && result[i] == 0)
            i++;

        // convert into string
        while (i < result.size()) {
            ans.push_back(result[i] + '0');
            i++;
        }

        return ans;
    }
};