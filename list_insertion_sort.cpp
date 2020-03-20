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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *temp,*ptr,*cur;
        int i;
        if(head == NULL || head->next == NULL)
            return head;
        temp = head->next;
        ptr = head;
        cur = head;
        while(temp != NULL)
        {
            if(temp->val < cur->val)
            {
                cur->next = temp->next;
                if(head->val > temp->val)
                {
                    temp->next = head;
                    head = temp;
                    //ptr = head;
                }
                else
                {
                    int flag = 0;
                    while(ptr->next != cur)
                    {
                        if(ptr->next->val > temp->val)
                        {
                            temp->next = ptr->next;
                            ptr->next = temp;
                            flag = 1;
                            break;
                        }
                        ptr = ptr->next;
                    }
                    if(flag != 1)
                    {
                        temp->next = ptr->next;
                        ptr->next = temp;
                    }
                    flag = 0;
                }
            }
            else
                cur = cur->next;
            temp = cur->next;
            ptr = head;
        }
        return head;
    }
};