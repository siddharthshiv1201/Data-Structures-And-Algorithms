class Solution {
  public:
    int getMaxWidth(Node* root) {
        if (root == NULL) return 0;

        int maxi = 0;
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();           // yahin store kar lo size
            vector<int> level;
            for (int i = 0; i < size; i++) {
                Node* temp = q.front();
                q.pop();
                level.push_back(temp->data);

                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
            ans.push_back(level);
        }
        
        for (int i = 0; i < ans.size(); i++) {
            maxi = max(maxi, (int)ans[i].size());
        }
        return maxi;            // ✅ yahin return karna hai
    }
};
