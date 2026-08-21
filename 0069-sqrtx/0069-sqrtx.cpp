class Solution {
public:
    int mySqrt(int x) {

        if(x<2) return x;
        
        int left = 1;
        int right = x/2;

        while(left<=right)
        {
            int m = left+(right-left)/2;

            if(m == x/m) return m;
            else if(m < x/m) left=m+1;
            else right = m-1;
        }
        return right;
        
    }
};