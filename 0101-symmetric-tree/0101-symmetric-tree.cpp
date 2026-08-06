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
    bool check(TreeNode* l,TreeNode* r)
    {
        if(l==nullptr && r==nullptr) return true;
        if(!l || !r) return false;
        if(l->val != r->val) return false;

        bool leftside=check(l->left,r->right);
        bool rightside=check(l->right,r->left);

        return (leftside && rightside && l->val==r->val);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        return check(root->left,root->right);
        
    }
};