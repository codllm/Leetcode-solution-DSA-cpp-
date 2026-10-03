class Solution {
public:
    int evalRPN(vector<string>& tokens) {
         stack<int> st;
            
         for(auto x: tokens){
            if (x == "+"|| x == "-"|| x== "*"||x== "/"){
                int s = st.top();
                st.pop();
                int f = st.top();
                st.pop();

                if (x=="+") st.push(f+s);
                else if(x=="-") st.push(f-s);
                else if(x=="*") st.push(f*s);
                else if(x=="/") st.push(f/s);
            }
            else{
                st.push(stoi(x));
            }
        }
        return st.top();
    }
};