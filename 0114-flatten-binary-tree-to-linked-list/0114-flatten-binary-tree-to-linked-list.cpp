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
    void flattenToList(TreeNode* root)
    {
        if(root==nullptr) return;

        flattenToList(root->left);
        flattenToList(root->right);

        TreeNode* temp = root->right;

        root->right = root->left;
        root->left = nullptr;
        TreeNode* curnt = root;
        while(curnt->right!=nullptr)
        {
            curnt = curnt->right;
        }
        curnt->right=temp;
    }
public:
    void flatten(TreeNode* root) {

        flattenToList(root);

        
    }
};