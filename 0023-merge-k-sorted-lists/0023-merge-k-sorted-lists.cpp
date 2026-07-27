class Solution {
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* temp = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }

        temp->next = l1 ? l1 : l2;
        return dummy.next;
    }

    ListNode* solve(vector<ListNode*>& lists, int left, int right) {
        if (left == right) return lists[left];

        int mid = (left + right) / 2;

        ListNode* l1 = solve(lists, left, mid);
        ListNode* l2 = solve(lists, mid + 1, right);

        return merge(l1, l2);
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;

        return solve(lists, 0, lists.size() - 1);
    }
};