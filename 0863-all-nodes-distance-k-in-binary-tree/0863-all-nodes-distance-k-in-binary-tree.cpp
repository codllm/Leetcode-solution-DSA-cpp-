/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int> ans;

    void bfs(TreeNode* root,
             unordered_map<TreeNode*, TreeNode*>& parent,
             int k)
    {
        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis;

        q.push(root);
        vis.insert(root);

        int edges = 0;

        while (!q.empty())
        {
            int size = q.size();

            if (edges == k)
            {
                while (!q.empty())
                {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return;
            }

            while (size--)
            {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !vis.count(node->left))
                {
                    vis.insert(node->left);
                    q.push(node->left);
                }

                if (node->right && !vis.count(node->right))
                {
                    vis.insert(node->right);
                    q.push(node->right);
                }

                if (parent.count(node) && !vis.count(parent[node]))
                {
                    vis.insert(parent[node]);
                    q.push(parent[node]);
                }
            }

            edges++;
        }
    }

    void dfs(TreeNode* root,
             unordered_map<TreeNode*, TreeNode*>& parent,
             TreeNode* target,
             int k)
    {
        if (root == nullptr)
            return;

        if (root == target)
        {
            // yahan target mil gaya,
            // ab isi node se BFS start kar do
            bfs(root, parent, k);
            return;
        }

        if (root->left)
            parent[root->left] = root;

        if (root->right)
            parent[root->right] = root;

        dfs(root->left, parent, target, k);
        dfs(root->right, parent, target, k);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        unordered_map<TreeNode*, TreeNode*> parent;

        dfs(root, parent, target, k);

        return ans;
    }
};