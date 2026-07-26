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

        while(head!=nullptr && head->val == val) head = head->next;

        if(head ==nullptr) return nullptr;
        ListNode* dummyhead = new ListNode(-1);//new dummy-list created
        ListNode* dummy = dummyhead;
        

        dummy->next = head;//new head of list created
        dummy = dummy->next;
        head = head->next;

        while( head!= nullptr)
        {
            if(head->val != val)
            {
                dummy->next = head;
                dummy = dummy->next;
            }
            head = head->next;
        }
        //end of list
        dummy->next = nullptr;

        return dummyhead->next;
        
    }
};