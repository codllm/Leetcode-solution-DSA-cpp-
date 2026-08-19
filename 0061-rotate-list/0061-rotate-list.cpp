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
    private:
    int length_of_list(ListNode* temp)
    {
        int count = 0;
        while(temp)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || !head->next) return head;

        int length = length_of_list(head);

        k = k % length;

        if(k==0) return head;

        int times = length - k;

        ListNode* prev = nullptr;
        ListNode* temp = head;

        while(times--)
        {
            prev = temp;
            temp = temp->next;
        }

        //1->2->3
        //temp is node(4)

        //now get the length - k listofNode
        ListNode* tail = temp;
        ListNode* newhead = temp;
        //newhaed is at node(4)
        //tail is actually 4->5
        while(tail->next)
        {
            tail = tail->next;
        }
        tail->next = head;
        //4->5->head(1);
        //3(prev)->nullptr
        prev->next = nullptr;

        return newhead;

        
    }
};