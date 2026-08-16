class NumArray {
public:
    unordered_map<int,int>mpp;
    
    NumArray(vector<int>& nums) {
        int prefix = 0;
        for(int i=0;i<nums.size();i++)
        {
            prefix+=nums[i];
            mpp[i] = prefix;            
        }
    }
    
    int sumRange(int left, int right) {

        if(left == 0) return mpp[right];

        return mpp[right]-mpp[left-1]; 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */