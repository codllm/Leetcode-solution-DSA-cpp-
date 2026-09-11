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
    ListNode* removeElements(ListNode* head, int val) {

        if(head==nullptr) return head;

        while(head && head->val == val) head = head->next;
        //first node head ki value jbtk same hai tbtk skip kro qki while run hone k liye first node(head) should not be head to head
        //otherwise nullptr(prev) wo join ho jayega

        if(!head) return nullptr;

        ListNode* prev = nullptr;
        ListNode* curnt = head;

        while(curnt)
        {
            if(curnt->val == val)
            {
                prev->next = curnt->next;
                curnt = curnt->next;
            }
            else
            {
                prev = curnt;
                curnt = curnt->next;
            }
        }
        return head;
        
    }
};