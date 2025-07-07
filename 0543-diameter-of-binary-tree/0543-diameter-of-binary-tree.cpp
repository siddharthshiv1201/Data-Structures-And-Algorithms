class Solution {
    private:
    int height(TreeNode* root){
        if(!root) return 0;

        int left=height(root->left);
        int right=height(root->right);

        int ans=max(left,right)+1;
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int op1=diameterOfBinaryTree(root->left);
        int op2=diameterOfBinaryTree(root->right);
        int op3=height(root->left)+height(root->right);
        int ans=max(op1,max(op2,op3));
        return ans;
    }
};