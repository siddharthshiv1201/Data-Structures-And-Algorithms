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
private:
    int height(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    TreeNode* ans(TreeNode* root) {
        if (root == NULL) return NULL;

        int hl = height(root->left);
        int hr = height(root->right);

        if (hl == hr) {
            return root;
        } else if (hl > hr) {
            return ans(root->left);
        } else {
            return ans(root->right);
        }
    }

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return ans(root);
    }
};