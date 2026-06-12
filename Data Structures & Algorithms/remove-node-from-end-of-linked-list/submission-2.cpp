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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first,*second;
        ListNode *dummy=new ListNode(0);
        first=dummy;dummy->next=head;
        second=head;

        while(n!=0)
        {
            second=second->next;n--;

        }

        while(second!=nullptr)
        {
            first=first->next;
            second=second->next;
        }
        first->next=first->next->next;
        return dummy->next;
        
    }
};
