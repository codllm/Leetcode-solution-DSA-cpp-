class Solution {
private:
    long long minhourfunction(vector<int>& piles, int m)
    {
        long long ans = 0; 
        
        for(auto x:piles)
        {
            ans+= x/m;

            if(x%m!=0) ans++;
        }
        
        return ans;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        long long l = 1;
        long long r = *max_element(piles.begin(), piles.end());

        long long ans = r;

        while(l <= r)
        {
            long long m = l + (r - l) / 2;

            long long hours = minhourfunction(piles, m);

            if(hours <= h)
            {       
                ans = m;       
                r = m - 1; 
            }
            else 
            {
                l = m + 1;  
            }
        }

        return ans;
    }
};