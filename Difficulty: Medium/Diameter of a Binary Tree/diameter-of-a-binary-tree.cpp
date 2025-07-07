class Solution {
  public:
    int maxDiameter = 0;

    int height(Node* root) {
        if (!root) return 0;

        int left = height(root->left);
        int right = height(root->right);

        maxDiameter = max(maxDiameter, left + right);

        return max(left, right) + 1;
    }

    int diameter(Node* root) {
        height(root);
        return maxDiameter;
    }
};
