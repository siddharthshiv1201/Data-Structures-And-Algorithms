class Solution{
  public:
    pair<int,int> helper(Node* root) {
        if(root == NULL)
            return {0, 0};
            
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        // If we include this node, we can't include its children
        int incl = root->data + left.second + right.second;
        
        // If we exclude this node, we can choose to include or exclude children
        int excl = max(left.first, left.second) + max(right.first, right.second);
        
        return {incl, excl};
    }

    int getMaxSum(Node *root) {
        auto res = helper(root);
        return max(res.first, res.second);
    }
};
