/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool solve(TreeNode* root1, TreeNode* root2)
    {
        // Both are null
        if (root1 == nullptr && root2 == nullptr)
            return true;

        // One is null
        if (root1 == nullptr || root2 == nullptr)
            return false;

        // Values must match
        if (root1->val != root2->val)
            return false;

        // Case 1: No flip
        bool noFlip =
            solve(root1->left, root2->left) &&
            solve(root1->right, root2->right);

        // Case 2: Flip
        bool flip =
            solve(root1->left, root2->right) &&
            solve(root1->right, root2->left);

        return noFlip || flip;
    }

public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return solve(root1, root2);
    }
};