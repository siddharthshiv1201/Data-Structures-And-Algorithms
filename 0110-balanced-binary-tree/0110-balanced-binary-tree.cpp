class Solution {
public:
    int leftSubtree(TreeNode* root) {
        if (!root) return 0;
        return max(leftSubtree(root->left), leftSubtree(root->right)) + 1;
    }

    int rightSubtree(TreeNode* root) {
        if (!root) return 0;
        return max(rightSubtree(root->left), rightSubtree(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;  

        if (abs(leftSubtree(root->left) - rightSubtree(root->right)) > 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);  // Check subtrees
    }
};
