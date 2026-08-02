class Solution {
    private:
    long findGCD(int a,int b)
    {
        while(b!=0)
            {
                int temp = b;
                b = a % b;
                a = temp;
            }
        return a;
    }
public:
    long long maxPairStrength(vector<int>& nums) {

        long long maxSrength = 0;
        for(int i=0;i<nums.size();i++)
            {
                for(int j=i+1;j<nums.size();j++)
                    {
                        if(i != j)
                        {
                            //find gcd here
                            long long gcd = findGCD(nums[i],nums[j]);
                            long long strength = (1LL*nums[i]*nums[j])/(gcd*gcd);
                            maxSrength = max(maxSrength,strength);
                            
                        }
                    }
            }
        return maxSrength;
        
    }
};