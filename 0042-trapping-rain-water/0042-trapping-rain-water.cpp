class Solution {
public:
    int trap(vector<int>& height) {

        stack<int>st;
        int water=0;
        for(int i=0;i<height.size();i++)
        {
            while(!st.empty() && height[st.top()]<height[i])
            {
                int mid=st.top();
                st.pop();
                int r=height[i];
                
                if(st.empty()) break;

                int l=height[st.top()];

                int ht = min(l, r) - height[mid];
                int width=i-st.top()-1;

                water+=ht*width;
            }
            st.push(i);
        }

        return water;
        
    }
};