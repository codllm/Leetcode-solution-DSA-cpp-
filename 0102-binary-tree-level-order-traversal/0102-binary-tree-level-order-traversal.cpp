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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root == nullptr) return {};
        queue<TreeNode*>q;
        q.push(root);

        vector<vector<int>>result;
        while(!q.empty())
        {
            int size = q.size();
            vector<int>temp;
            for(int i=0;i<size;i++)
            {
                TreeNode* topnode = q.front();
                q.pop();

                temp.push_back(topnode->val);

                if(topnode->left) q.push(topnode->left);
                if(topnode->right) q.push(topnode->right);
            }

            result.push_back(temp);
                   
        }
        return result;
        
    }
};