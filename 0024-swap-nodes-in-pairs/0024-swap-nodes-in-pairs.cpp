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
    ListNode* swapPairs(ListNode* head) {

        if (!head || !head->next) return head;
        
        ListNode* prev=nullptr;
        ListNode* first = head;
        ListNode* second = head->next;

        bool firstpasshead = true;
        while(first && first->next)
        {
            ListNode* nextLeftList = second->next;

            second->next = first;
            first->next = nextLeftList;

            if(firstpasshead == true)
            {
                head = second;
                
                firstpasshead = false;
            }
            else
            {
                prev->next = second;
            }
            //prev here connecting two seprate node list into one of before + after part together
            //2-1
            //4-3-5
            //prev does 2->1->(prev)->4->3->5
            prev = first;
            first = nextLeftList;

            if(first)
            {
                second = first->next;
            }
        }

        return head;
        
    }
};