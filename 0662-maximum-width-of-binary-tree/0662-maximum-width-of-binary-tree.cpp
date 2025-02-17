class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        queue<pair<TreeNode*, long long>> q; // Change int to long long
        q.push({root, 0});
        
        while (!q.empty()) {
            int size = q.size();
            long long min = q.front().second; // Store the minimum index in long long
            long long first, last;
            
            for (int i = 0; i < size; i++) {
                long long curIndex = (long long)q.front().second - min; // Avoid overflow
                TreeNode* node = q.front().first;
                q.pop();
                
                if (i == 0) first = curIndex;
                if (i == size - 1) last = curIndex;

                if (node->left) {
                    q.push({node->left, (curIndex * 2) + 1});
                }
                if (node->right) {
                    q.push({node->right, (curIndex * 2) + 2});
                }
            }
            ans = max(ans, (int)(last - first + 1));
        }
        return ans;
    }
};
