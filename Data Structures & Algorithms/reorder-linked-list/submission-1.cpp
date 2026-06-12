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
    void reorderList(ListNode* head) {
        ListNode *l1=head, *l2=head;
        while(l2!=nullptr && l2->next!=nullptr)
        {
            l1=l1->next;
            l2=l2->next->next;
        }

        l2 = l1->next;      
        l1->next = nullptr; 
        l1 = head;         

        ListNode *prev,*curr,*nextNode;
        prev=nullptr;curr=l2;

        while(curr)
        {
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }

        l2=prev;
        ListNode *dummy=new ListNode(0);
        ListNode *tail=dummy;

        while(l1!=nullptr && l2!=nullptr)
        {
            tail->next=l1;
            l1=l1->next;
            tail=tail->next;
            tail->next=l2;
            l2=l2->next;
            tail=tail->next;
        }
        if(l1!=nullptr)
        {
            tail->next=l1;
        }




    }
};
