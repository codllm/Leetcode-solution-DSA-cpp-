class Solution {
    unordered_map<TreeNode*, int> dp;

    int solve(TreeNode* root) {
        if (root == nullptr)
            return 0;

        if (dp.count(root))
            return dp[root];

        int take = root->val;

        if (root->left)
            take += solve(root->left->left) + solve(root->left->right);

        if (root->right)
            take += solve(root->right->left) + solve(root->right->right);

        int notTake = solve(root->left) + solve(root->right);

        return dp[root] = max(take, notTake);
    }

public:
    int rob(TreeNode* root) {

        //also we can say this problem of tree dfs n dp
        //we have the choice of taken and not taken
        return solve(root);
    }
};