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
    int maxLen = 0;

    int pathLen(TreeNode* root, int parentVal) {
        if (root == nullptr || root->val != parentVal)
            return 0;

        return 1 + max(pathLen(root->left, parentVal),
                       pathLen(root->right, parentVal));
    }

    void solve(TreeNode* root) {
        if (root == nullptr)
            return;

        int leftLen = pathLen(root->left, root->val);
        int rightLen = pathLen(root->right, root->val);

        maxLen = max(maxLen, leftLen + rightLen);

        solve(root->left);
        solve(root->right);
    }

public:
    int longestUnivaluePath(TreeNode* root) {
        solve(root);
        return maxLen;
    }
};