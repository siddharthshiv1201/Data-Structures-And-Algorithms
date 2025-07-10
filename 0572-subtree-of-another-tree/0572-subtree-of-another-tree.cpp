
class Solution {
public:
    bool helper(TreeNode* t, TreeNode* s){
        if(t==NULL && s==NULL){
            return true;
        }
        if(t==NULL || s==NULL){
            return false;
        }
        if(t->val==s->val){
            return helper(t->left,s->left)&&helper(t->right,s->right);
        }

        return false;
    }
    bool isSubtree(TreeNode* t, TreeNode* s) {
        if(t==NULL) return false;
        if(helper(t,s)){
            return true;
        }
        return isSubtree(t->left,s)||isSubtree(t->right,s);
        
    }
};