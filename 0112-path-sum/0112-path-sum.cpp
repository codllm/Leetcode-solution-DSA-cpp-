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
    bool solve(TreeNode* root,int targetSum)
    {
        if(root==nullptr) return false;
        if(!root->left && !root->right && targetSum==root->val) return true;
        int left = solve(root->left,targetSum-root->val);
        int right = solve(root->right,targetSum-root->val);

        return left || right;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        return solve(root,targetSum);
        
    }
};