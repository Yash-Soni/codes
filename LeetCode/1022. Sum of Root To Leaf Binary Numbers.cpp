class Solution {
public:
    int sum = 0;
    void find(TreeNode *root, int tsum)
    {
        if(root == NULL)
            return;
        tsum = 2*tsum + root->val;
        if(root->left == NULL && root->right == NULL)
            sum += tsum;
        find(root->left, tsum);
        find(root->right, tsum);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        if(root == NULL)
            return 0;
        int tsum=0;
        find(root, tsum);
        
        return sum;
    }
};
