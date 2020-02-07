/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *tem = new ListNode(head->val);
        ListNode *cur = new ListNode(head->val);
        ListNode *ptr = new ListNode(head->val);
        tem = head;     cur = head;     ptr = head;
        ListNode *p,*q;
        int i,j;
        i = 1;      j=1;
        while(i<m)
        {
            cur = tem;
            tem = tem->next;
           
            i++;
        }
        while(j<n)
        {
            ptr = ptr->next;
            j++;
        }
        while(tem != ptr)
        {
            p = tem->next;
            tem->next = ptr->next;
            q = tem;
            tem = p;
            ptr->next = q;
        }
        if(m == 1)
        {
            head = ptr;
        }
        else
            cur->next = ptr;
        return head;
    }
};