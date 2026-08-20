class Solution {
private:
    int ans = 0;

    int solve(TreeNode* root)
    {
        if(root == nullptr)
            return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        ans += abs(left - right);

        return left + right + root->val;
    }

public:
    int findTilt(TreeNode* root) {

        solve(root);
        return ans;
    }
};