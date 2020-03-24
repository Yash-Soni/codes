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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *tem,*ptr;
        int flag = 0;
        if(head == NULL || head->next == NULL)
            return head;
        tem = head;
        ptr = head;

        while(tem != NULL)
        {
            while(tem->next != NULL  && tem->val == tem->next->val)
            {
                tem->next = tem->next->next;
                flag = 1;
            }
            if(flag == 1)
            {
                if(tem == head)
                {
                    if(tem->next == NULL)
                        return NULL;
                    head = tem->next;
                    ptr = head;
                    ptr->next = head->next;
                }
                else
                {
                    ptr->next = tem->next;
                }
                flag = 0;
            }
            else
            {
                if(tem != head)
                    ptr = ptr->next;
                ptr->next = tem->next;
            }
            tem = tem->next;
        }
        return head;
    }
};