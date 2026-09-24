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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //add two number

        ListNode* dummy = new ListNode(0);
        ListNode* curnt = dummy;
        int carry = 0;
        while(l1 || l2 || carry!=0)
        {
            int l1val = (l1==nullptr) ? 0 : l1->val;
            int l2val = (l2==nullptr) ? 0 : l2->val;
            //
            int sum = l1val+l2val+carry;
            carry = sum/10;
            curnt->next = new ListNode(sum%10);;
            curnt = curnt->next;
            
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;

        }
        return dummy->next;
        
    }
};