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
    bool check(TreeNode* node,long MinVal,long MaxVal){
        if(!node)
        return true;
        else if(node->val<=MinVal || node->val>=MaxVal){
            return false;
        }
        return check(node->left,MinVal,node->val) && check(node->right,node->val,MaxVal);
    }
    bool isValidBST(TreeNode* root) {
        long MinVal = LONG_MIN,MaxVal = LONG_MAX;
        return check(root,MinVal,MaxVal);
    }
};