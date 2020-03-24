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
        ListNode *cur,*ptr,*tem1,*tem2;
        if(head == NULL || head->next == NULL)
            return head;
        cur = head;
        ptr = head->next;

        if(ptr->next == NULL || ptr->next->next == NULL)
        {
            cur->next = ptr->next;
            ptr->next = cur;
            head = ptr;
            return head;
        }

        tem1 = ptr->next;
        tem2 = tem1->next;

        ptr->next = cur;
        cur->next = tem2;
        head = ptr;
        while(tem1 != NULL && tem2 != NULL)
        {
            ptr = tem2;
            cur = tem1;
            tem1 = ptr->next;

            if(tem1 != NULL)
                tem2 = tem1->next;
            else
                tem2 = NULL;

            if(tem2 == NULL)
                cur->next = tem1;
            else
                cur->next = tem2;

            ptr->next = cur;

        }
        if(tem1 != NULL && tem2 == NULL)
        {
            cur->next = tem1;
            tem1->next = NULL;
        }

        return head;
    }
};