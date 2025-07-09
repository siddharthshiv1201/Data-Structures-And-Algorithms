
class Solution {
public:
    void helper(TreeNode* root){
        if(root==NULL) return;
        swap(root->left,root->right);
        helper(root->left);
        helper(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
        
    }
};