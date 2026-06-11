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
        if(!head||!head->next)
        {
            return nullptr;
        }

        int num=0;
        ListNode *start=head;

        while(start!=nullptr)
        {
            num++;
            start=start->next;
        }
        num=num-n;
        
        ListNode *a=head;
        ListNode *b=nullptr;
        if(num==0)
        {
            head=head->next;
            return head;
        }

        while(num!=0)
        {
            b=a;
            
            a=a->next;
            num--;
        }
        b->next=a->next;
        return head;






        
    }
};
