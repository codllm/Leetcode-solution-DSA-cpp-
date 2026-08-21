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
    void solve(TreeNode* root,string &s)
    {
        if(root==nullptr) return;

        s+='(';
        s+=to_string(root->val);

        solve(root->left,s);

        if(!root->left && root->right) s+="()";
        
        solve(root->right,s);

        s+=')';
        
    }
public:
    string tree2str(TreeNode* root) {

        string s;
        solve(root,s);
        //i have added the extra '(' and ')' from both the end
        //so remove one extra from both the end

        return s.substr(1,s.size()-2);
        
    }
};