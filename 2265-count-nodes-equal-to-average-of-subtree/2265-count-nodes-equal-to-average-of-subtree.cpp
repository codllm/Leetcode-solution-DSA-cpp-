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
    int ans = 0;
    private:
    pair<int,int> solve(TreeNode* root)
    {
        if( root ==nullptr ) return {0,0};
        
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);

        int sum =  left.first + right.first + root->val;

        int avg = (sum) /(left.second+right.second+1);

        if(root->val == avg) ans++;

        //return {sum of subtree and totalnode}

        return {sum,left.second+right.second+1};

    }
public:
    int averageOfSubtree(TreeNode* root) {

        if(root==nullptr) return 0;

        solve(root);

        return ans;
        
    }
};