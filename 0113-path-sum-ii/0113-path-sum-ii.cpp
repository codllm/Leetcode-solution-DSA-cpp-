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
    void solve(TreeNode* root,int targetSum,vector<int>& temp,vector<vector<int>>& result)
    {
        if(root==nullptr) return;
        temp.push_back(root->val);
        if(!root->left && !root->right && root->val==targetSum)//at leaf node
        {
            result.push_back(temp);
        }

        
        solve(root->left,targetSum-root->val,temp,result);
        solve(root->right,targetSum-root->val,temp,result);

        temp.pop_back();
        //beach mein pop isliye nhi kr rhe ha qki root node done k sath rhega with left child and right child 
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<int>temp;
        vector<vector<int>>result;
        solve(root,targetSum,temp,result);
        return result;
        
    }
};