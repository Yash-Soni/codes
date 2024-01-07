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
        getTraversal(root->left, order);
        getTraversal(root->right, order);
        order.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> order;
        getTraversal(root, order);
        return order;
    }
};
