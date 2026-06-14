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

        if(head==nullptr)
        {
            return nullptr;
        }
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *groupPrev=dummy;
        ListNode *traverse=dummy;


        while(traverse!=nullptr)
        {
            for(int i=0;i<k &&traverse!=nullptr;i++)
            {
                traverse=traverse->next;
            }
            if(traverse==nullptr)
            {
                break;
            }
            ListNode *groupNext= traverse->next;
            traverse->next=nullptr;
            ListNode *prev, *curr, *nextNode;
            prev=nullptr;curr=groupPrev->next;
            while(curr)
            {
                nextNode=curr->next;
                curr->next=prev;
                prev=curr;
                curr=nextNode;
            }
            groupPrev->next->next=groupNext;
            ListNode *savePrev=groupPrev->next;
            groupPrev->next=prev;

            //updating groupPrev for the next iteration
            traverse=groupPrev=savePrev;
            


        }
        return dummy->next;
        
    }
};
