
class Solution {
public:
    // Function to check if placing num at board[row][col] is valid
    bool isSafe(vector<vector<char>>& board, int row, int col, char num) {
        // Check row & column
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num || board[i][col] == num) return false;
        }

        // Check 3x3 box
        int startRow = (row / 3) * 3, startCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[startRow + i][startCol + j] == num) return false;
            }
        }

        return true; // Valid placement
    }

    // Recursive function to solve Sudoku
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') { // Found an empty cell
                    for (char num = '1'; num <= '9'; num++) {
                        if (isSafe(board, row, col, num)) {
                            board[row][col] = num; // Place the number

                            if (solve(board)) return true; // Recur for the next empty cell

                            board[row][col] = '.'; // Backtrack if no solution found
                        }
                    }
                    return false; // No valid number found, trigger backtracking
                }
            }
        }
        return true; // All cells are filled correctly
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
