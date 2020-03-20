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
    ListNode *detectCycle(ListNode *head) {
        ListNode *ptr1,*ptr2;
        ptr1 = head;
        ptr2 = head;
        if(head == NULL)
        {
            return NULL;
        }
        while(ptr1 != NULL && ptr2 != NULL)
        {
            ptr1 = ptr1->next;
            if(ptr2->next == NULL || ptr2->next->next == NULL)
                return NULL;
            ptr2 = ptr2->next->next;
            if(ptr1 == ptr2)
            {
                ptr2 = head;
                while(ptr1 != ptr2)
                {
                    ptr1 = ptr1->next;
                    ptr2 = ptr2->next;
                }
                return ptr1;
            }
        }
        return NULL;
    }
};