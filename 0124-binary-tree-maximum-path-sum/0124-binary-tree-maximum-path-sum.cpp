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
    int maxpath = INT_MIN;
    private:
    int solve(TreeNode* root)
    {
        if(root==nullptr) return 0;

        int right = max(0,solve(root->right));
        int left = max(0,solve(root->left));

        maxpath = max(maxpath,left+right+root->val);

        return max(left,right)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {

        int ans = solve(root);

        return maxpath;
    }
};