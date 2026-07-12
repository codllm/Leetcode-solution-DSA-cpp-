class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* left = dummy;
        ListNode* right = dummy;

        for(int i = 0; i <= n; i++) {
            right = right->next;
        }

        while(right != NULL) {
            left = left->next;
            right = right->next;
        }

        ListNode* removeNode = left->next;
        left->next = removeNode->next;
        delete removeNode;

        return dummy->next;
    }
};