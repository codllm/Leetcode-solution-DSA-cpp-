/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    TreeNode* solve(vector<int>& nums,int left,int right)
    {
        if(right<left) return nullptr;

        int mid = left + (right-left)/2;

        TreeNode* rootnode = new TreeNode(nums[mid]);
        rootnode->left = solve(nums,left,mid-1);
        rootnode->right = solve(nums,mid+1,right);

        return rootnode;

    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        //sorted array se binary tree bnana haa right
        int left = 0;
        int right = nums.size()-1;
        return solve(nums,left,right);
        
    }
};