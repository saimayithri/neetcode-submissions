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
        vector <int>li1,li2;
        while(l1!=nullptr)
        {
            (li1).push_back(l1->val);
            
            l1=l1->next;
            


        }
        while(l2!=nullptr)
        {   (li2).push_back(l2->val);
            
            l2=l2->next;

        }
          
        int n1 = li1.size(), n2 = li2.size();
        if(n1 < n2) li1.resize(n2, 0);
        else li2.resize(n1, 0);
        int carry=0;
        vector <int> result;
        for(int i=0;i<li1.size();i++)
        {
            int sum=li1[i]+li2[i]+carry;
            result.push_back(sum%10);
            carry=sum/10;
        }
        if(carry)
        {
            result.push_back(carry);
        }
            ListNode* newhead=new ListNode(0);
            ListNode* curr=newhead;

            for(int v:result)
            {
                curr->next=new ListNode(v);
                curr=curr->next;
            }
            
        
        return (newhead->next);


        
    }
};
