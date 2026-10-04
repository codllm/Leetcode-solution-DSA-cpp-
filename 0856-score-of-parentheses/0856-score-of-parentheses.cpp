class Solution {
public:
    int scoreOfParentheses(string s) {

        stack<int>st;
        st.push(0);

        for(auto ch:s)
        {
            if(ch=='(') st.push(0);
            else
            {
                int innerscore = st.top();
                st.pop();

                int curntscore = max(2*innerscore,1);
                st.top()+=curntscore;
            }
        }
        return st.top();



    }
};