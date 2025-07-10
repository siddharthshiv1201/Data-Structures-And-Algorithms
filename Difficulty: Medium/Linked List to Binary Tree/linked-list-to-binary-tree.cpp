class Solution {
  public:
    TreeNode* linkedListToBinaryTree(Node* head) {
        vector<TreeNode*> v;
        Node* temp=head;
        while(temp!=NULL){
            v.push_back(new TreeNode(temp->data));
            temp=temp->next;
        }
        for(int i=0 ;i<v.size(); i++){
            int l=2*i+1;
            int r=2*i+2;
            
            if(l<v.size()){
                v[i]->left=v[l];
            }
            if(r<v.size()){
                v[i]->right=v[r];
            }
            
        }
        return v[0];
        // code here
        
    }
};