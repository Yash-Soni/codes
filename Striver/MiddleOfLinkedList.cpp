class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==nullptr || head->next ==nullptr) return head;
        ListNode* cur=head;
        ListNode* prev=nullptr;
        int size=0;
        while(cur) {
            size++;
            cur=cur->next;
        }
        int num = size/2, i=0;
        cur=head;
        while(i<num) {
            prev=cur;
            cur=cur->next;
            i++;
        }
        return cur;
    }
};
