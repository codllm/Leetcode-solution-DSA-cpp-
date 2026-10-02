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
    void postordered(TreeNode* root,vector<int>& ans)
    {
        if(root==nullptr) return;

        postordered(root->left,ans);
        postordered(root->right,ans);
        ans.push_back(root->val);

    }
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int>ans;
        postordered(root,ans);
        return ans;
        
    }
};