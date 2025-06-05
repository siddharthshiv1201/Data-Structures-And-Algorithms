class Solution {
public:
    static int dp[1002][1002];  // Global/static declaration

    int knapsackUtil(int W, vector<int>& val, vector<int>& wt, int n) {
        if (n == 0 || W == 0) return 0;

        if (dp[n][W] != -1) return dp[n][W];

        if (wt[n - 1] <= W) {
            return dp[n][W] = max(
                val[n - 1] + knapsackUtil(W - wt[n - 1], val, wt, n - 1),
                knapsackUtil(W, val, wt, n - 1)
            );
        } else {
            return dp[n][W] = knapsackUtil(W, val, wt, n - 1);
        }
    }

    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        memset(dp, -1, sizeof(dp));  // ✅ Proper place to memset
        int n = wt.size();
        return knapsackUtil(W, val, wt, n);
    }
};

// ✅ Define static dp outside the class
int Solution::dp[1002][1002];
