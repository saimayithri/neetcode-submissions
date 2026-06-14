
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
        {
            return list2;
        }
        if(list2 == nullptr)
        {
            return list1;
        }

        ListNode* dummy=new ListNode(0);
        ListNode* tail = dummy;
        ListNode* l1 = list1;
        ListNode* l2 = list2;

        while(l1!=nullptr && l2!=nullptr)
        {
            if(l1->val<=l2->val)
            {
                tail->next=l1;
                l1=l1->next;
            }
            else 
            {
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;


        }

        if(l2!=nullptr)
        {
            tail->next=l2;
        }
        if(l1!=nullptr)
        {
            tail->next=l1;
        }

        return dummy->next;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
        {
            return nullptr;
        }

        for(int i=1;i<lists.size();i++)
        {
            if(lists[i-1]==nullptr)
            {
                continue;
            }
            lists[i]=mergeTwoLists(lists[i-1],lists[i]);

        }
        return lists[lists.size()-1];
       
    }
};
