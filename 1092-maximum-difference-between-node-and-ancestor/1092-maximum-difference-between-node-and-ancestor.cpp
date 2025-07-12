class Solution {
public:
int result=0;
    void dfs(TreeNode* root, int mini, int maxi){
        if(!root) return ;

        mini=min(mini,root->val);
        maxi=max(maxi,root->val);

        if(!root->left && !root->right){
            result=max(result,maxi-mini);
            return ;
        }

        dfs(root->left,mini,maxi);
        dfs(root->right,mini,maxi);
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root,root->val, root->val);
        return result;
        
    }
};