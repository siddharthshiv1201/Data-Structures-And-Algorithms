class Solution {
  public:
    // Function to check if S is a subtree of tree T.
    bool helper(Node* T, Node* S){
        if(T==NULL && S==NULL){
            return true;
        }
        if(T==NULL || S==NULL){
            return false;
        }
        if(T->data==S->data){
            return helper(T->left,S->left)&&helper(T->right,S->right);
        }
        return false;
    }
    bool isSubTree(Node* T, Node* S) {
        // Your code here
        if(T==NULL) return false;
        
        if(helper(T,S)){
            return true;
        }
        return isSubTree(T->left,S)||isSubTree(T->right,S);
        
        
    }
};