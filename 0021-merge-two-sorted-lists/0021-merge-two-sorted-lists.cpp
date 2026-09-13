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
    ListNode* mergeTwoLists(ListNode* A, ListNode* B) {

        ListNode* dummy = new ListNode(INT_MIN);
        ListNode* curnt = dummy;
        while(A && B)
        {
            if(A->val < B->val)
            {
                curnt->next = A;
                A = A->next;
                
            }
            //
            else
            {
                curnt->next = B;
                B = B->next;
            }
            curnt = curnt->next;
        }

        while(A)
        {
            curnt->next = A;
            curnt=curnt->next;
            A= A->next;
        }
        while(B)
        {
            curnt->next = B;
            curnt = curnt->next;
            B=B->next;
        }    
        return dummy->next;
    }
};