class Solution {
private:
    long long minhourfunction(vector<int>& piles, int m)
    {
        long long ans = 0; 
        
        for(int i = 0; i < piles.size(); i++)
        {
            ans += (piles[i] + m - 1) / m; 
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