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
    void deleteNode(ListNode* node) {
        ListNode *tem=node->next;
        while(tem->next != NULL) {
            node->val = tem->val;
            node = tem;
            tem = tem->next;
        }
        node->val = tem->val;
        node->next = NULL;
    }
};
