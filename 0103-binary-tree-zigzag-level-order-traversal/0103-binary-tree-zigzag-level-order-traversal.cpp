class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if(root == nullptr) return {};

        queue<TreeNode*> dq;
        dq.push(root);
        vector<vector<int>> ans;
        bool zigzag = false;

        while(!dq.empty())
        {
            int size = dq.size();
            vector<int> temp;

            for(int i=0;i<size;i++)
            {
                TreeNode* node = dq.front();
                dq.pop();

                temp.push_back(node->val);
                if(node->left) dq.push(node->left);
                if(node->right) dq.push(node->right);
            }
            if(zigzag == true)
            {
                reverse(temp.begin(), temp.end());
            }

            ans.push_back(temp);

            zigzag = !zigzag;
        }

        return ans;
    }
};