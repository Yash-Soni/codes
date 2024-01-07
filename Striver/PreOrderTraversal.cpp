/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void getTraversal(TreeNode* root, vector<int>& order) {
        if(!root) return;
        order.push_back(root->val);
        if(root->left) getTraversal(root->left, order);
        if(root->right) getTraversal(root->right, order);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> order;
        if(root==NULL) return order;
        if(!root->left && !root->right) {
            order.push_back(root->val);
            return order;
        }
        getTraversal(root, order);
        return order;
    }
};
