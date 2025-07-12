
class Solution {
  public:
   void count(Node* root,int maxi,int &ans)
{
    if(root==NULL)
    {
        return ;
    }
    int temp=maxi-root->data;
    ans=max(ans,temp);
    count(root->left,max(maxi,root->data),ans);
    count(root->right,max(maxi,root->data),ans);
}
int maxDiff(Node* root)
{
    if(!root->left && !root->right) return INT_MIN;
    int ans=INT_MIN;
    int maxi=root->data;
    count(root->left,maxi,ans);
    count(root->right,maxi,ans);
    return ans;
}
};