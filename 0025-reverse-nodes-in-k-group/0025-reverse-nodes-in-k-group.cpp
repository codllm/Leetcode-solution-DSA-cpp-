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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* left = head;
        ListNode* right = head;

        ListNode* newhead=head;
        ListNode* prevTail=nullptr;

        int count=1;

        while(right)
        {
            if(count < k  && right!=nullptr)
            {
                right=right->next;
                count++;
            }

            if(count == k && right)
            {
                ListNode* curnt= left;
                ListNode* prev= right->next;

                int temp=k;
                while(temp--)
                {
                    ListNode* nextnode = curnt->next;

                    curnt->next=prev;
                    prev=curnt;
                    curnt=nextnode;
                }

                if(head==left)
                {
                    newhead=prev;
                }

                if(prevTail)
                {
                    prevTail->next=prev;
                }
                prevTail=left;
                
                left=curnt;
                right=curnt;

                count=1;
            }
        }

        return newhead;
        
    }
};