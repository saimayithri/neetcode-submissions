class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next; // store next node
            curr->next = prev;               // reverse the link
            prev = curr;                     // move prev one step forward
            curr = nextNode;                 // move curr one step forward
        }

        return prev; // prev will be the new head
    }
};
