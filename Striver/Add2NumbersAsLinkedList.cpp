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
    // ListNode* reverseList(ListNode *head) {
    //     ListNode next=nullptr, prev=nullptr, cur=head;
    //     while(cur) {
    //         next = cur->next;
    //         cur->next= prev;
    //         prev=cur;
    //         cur=next;
    //     }
    //     return prev;
    // }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer = new ListNode();
        ListNode* head = answer;
        int carry = 0;

        while(l1 || l2) {
            ListNode* tem = new ListNode();
            int sum=0;
            if(l1 && l2) {
                sum = l1->val + l2->val + carry;
            } else if(l1) {
                sum = l1->val + carry;
            } else {
                sum = l2->val + carry;
            }
            carry = sum > 9 ? 1 : 0;
            tem->val = sum%10;
            tem->next = nullptr;
            answer->next= tem;
            
            answer = answer->next;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        if(carry) {
            ListNode* tem = new ListNode();
            tem->val = carry;
            tem->next = nullptr;
            answer->next = tem;
        }
        return head->next;
    }
};
