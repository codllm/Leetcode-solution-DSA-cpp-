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
    unordered_map<int,int>mpp;
    private:
    int solve(TreeNode* root)
    {
        if(root==nullptr) return 0;

        int left = solve(root->left);

        int right = solve(root->right);

        int subTreeSum = root->val+left+right;

        //increase the freq of subtree sum
        mpp[subTreeSum]++;
        
        return subTreeSum;

    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {

        if(root==nullptr) return {};

        int ans = solve(root);

        int maxFreq = 0;

        for(auto it:mpp)
        {
            maxFreq = max(maxFreq,it.second);
        }
        vector<int>result;

        for(auto it:mpp)
        {
            if(it.second == maxFreq) result.push_back(it.first);
        }
        return result;
        
    }
};