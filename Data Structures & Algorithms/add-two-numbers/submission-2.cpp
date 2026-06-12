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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode *dummy=new ListNode(0);
        ListNode *tail=dummy;
        while(l1!=nullptr || l2!=nullptr || carry !=0)
        {
            int val1=0,val2=0;
            if(l1){val1=l1->val;l1=l1->next;}
            if(l2){val2=l2->val;l2=l2->next;}

            int sum = val1+val2+carry;
            carry=sum/10;
            int value = sum%10;
            ListNode *newNode=new ListNode(value);
            tail->next=newNode;
            tail=tail->next;

        }
        return dummy->next;
        
    }
};
