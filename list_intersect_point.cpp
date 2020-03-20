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
    ListNode* swapPairs(ListNode* head) {
        ListNode *tem,*cur,*ptr;
        if(head == NULL || head->next ==NULL)
            return head;
        // cur = new ListNode(head->val);
        // ptr = new ListNode(head->next->val);
        // tem = new ListNode(head->val);
        
        tem = ptr->next;        cout<<"tem "<<tem->val<<", ";
        ptr->next = cur;        cout<<"ptr "<<ptr->val<<", ";
        if(tem->next != NULL)
            cur->next = tem->next;
        
        head = ptr;             cout<<"cur "<<cur->val<<", ";
        while(cur->next !=NULL && cur->next->next != NULL)
        {
            cur = tem;
            ptr = cur->next;
            tem = ptr->next;
            
            ptr->next = cur;
            cur->next = tem->next;
        }
        
        return head;
    }
};