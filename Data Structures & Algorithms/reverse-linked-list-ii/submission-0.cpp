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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        ListNode *dummy=new ListNode(0);
        ListNode *tail= dummy;
        dummy->next=head;

        ListNode *start=dummy, *end=dummy;int l=0, r=0;
        while(l!=left-1)
        {
            start=start->next;l++;
        }
        while(r!=right)
        {
            end=end->next;r++;

        }
        ListNode *curr,*prev, *nextNode;
        prev=nullptr; curr =start->next;ListNode* stop = end->next;

        while(curr!=stop)
        {
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;curr=nextNode;
        }
        
        ListNode* tailOfReversedPart = start->next; 

        tailOfReversedPart->next = curr;
        start->next=prev;
        return dummy->next;
        
    }
};