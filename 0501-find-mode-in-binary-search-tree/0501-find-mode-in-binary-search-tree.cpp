class Solution {
    int maxfreq = 0;
    int curntval = 0;
    int curntfreq = 0;
    bool firstNode = true;
    vector<int> temp;

    void dfs(TreeNode* root)
    {
        if(root == nullptr)
            return;

        dfs(root->left);

        if(firstNode)
        {
            curntval = root->val;
            curntfreq = 1;
            firstNode = false;
        }
        else if(root->val == curntval)
        {
            curntfreq++;
        }
        else
        {
            curntval = root->val;
            curntfreq = 1;
        }

        if(curntfreq > maxfreq)
        {
            temp.clear();
            maxfreq = curntfreq;
        }

        if(curntfreq == maxfreq)
        {
            temp.push_back(root->val);
        }

        dfs(root->right);
    }

public:
    vector<int> findMode(TreeNode* root)
    {
        dfs(root);
        return temp;
    }
};