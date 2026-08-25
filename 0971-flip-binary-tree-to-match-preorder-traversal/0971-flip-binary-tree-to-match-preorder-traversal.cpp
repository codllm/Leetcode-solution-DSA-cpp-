class Solution {
private:
    vector<int> ans;
    int idx = 0;

    bool dfs(TreeNode* root, vector<int>& voyage)
    {
        if (root == nullptr)
            return true;

        if (root->val != voyage[idx])
            return false;

        idx++;

        // Flip needed
        if (root->left && idx < voyage.size() &&
            root->left->val != voyage[idx])
        {
            ans.push_back(root->val);

            return dfs(root->right, voyage) &&
                   dfs(root->left, voyage);
        }

        return dfs(root->left, voyage) &&
               dfs(root->right, voyage);
    }

public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage)
    {
        if (!dfs(root, voyage))
            return {-1};

        return ans;
    }
};