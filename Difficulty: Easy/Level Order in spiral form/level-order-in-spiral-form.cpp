class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        vector<vector<int>> preans;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            
            for(int i = 0; i < size; i++) {
                Node* temp = q.front();
                q.pop();
                level.push_back(temp->data);
                
                if(temp->left) {
                    q.push(temp->left);
                }
                if(temp->right) {
                    q.push(temp->right);
                }
            }
            preans.push_back(level);
        }
        for(int i = 0; i < preans.size(); i++) {
            if(i % 2 == 0) {
                // right to left
                reverse(preans[i].begin(), preans[i].end());
            }
            for(int val : preans[i]) {
                ans.push_back(val);
            }
        }
        
        return ans;
    }
};
