class Solution {
public:
    int winner(int n, int k) {
        if (n == 1) return 0; // Base case: Only one person left (0-based index)
        
        // Recursive step: Find the winner of (n-1) and shift index
        return (winner(n - 1, k) + k) % n;
    }

    int findTheWinner(int n, int k) {
        return winner(n, k) + 1; // Convert 0-based index to 1-based index
    }
};
