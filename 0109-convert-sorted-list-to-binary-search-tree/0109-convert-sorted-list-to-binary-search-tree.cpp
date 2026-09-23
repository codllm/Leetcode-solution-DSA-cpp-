/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* solve(vector<int>& list,int left,int right)
    {
        if(left > right) return nullptr;

        int mid=left+(right-left)/2;
        TreeNode* root = new TreeNode(list[mid]);
        root->left=solve(list,left,mid-1);
        root->right=solve(list,mid+1,right);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {

        //basic simple brute force approcuh list to vector array conversion 
        // time complex==0(n);
        //space complex==0(stack(n)+vector array 0(n))=0(n)
        vector<int>list;
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            list.push_back(temp->val);
            temp=temp->next;
        }

        return solve(list,0,list.size()-1);        
    }
};