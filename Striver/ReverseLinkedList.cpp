class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *next=nullptr, *prev=nullptr, *cur=head;
        while(cur) {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
};
