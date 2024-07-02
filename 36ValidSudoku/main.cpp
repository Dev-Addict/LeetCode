#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (!isValidRow(board, i) || !isValidCol(board, i) || !isValidBox(board, i)) {
                return false;
            }
        }

        return true;
   }

    bool isValidRow(vector<vector<char>>& board, int row) {
        vector<bool> visited(9, false);

        for (int i = 0; i < 9; i++) {
            if (board[row][i] == '.') continue;
            if (visited[board[row][i] - '1']) {
                return false;
            }

            visited[board[row][i] - '1'] = true;
        }

        return true;
    }

    bool isValidCol(vector<vector<char>>& board, int col) {
        vector<bool> visited(9, false);

        for (int i = 0; i < 9; i++) {
            if (board[i][col] == '.') continue;
            if (visited[board[i][col] - '1']) return false;

            visited[board[i][col] - '1'] = true;
        }

        return true;
    }

    bool isValidBox(vector<vector<char>>& board, int box) {
        vector<bool> visited(9, false);

        int startRow = (box / 3) * 3;
        int startCol = (box % 3) * 3;

        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == '.') continue;
                if (visited[board[i][j] - '1']) return false;

                visited[board[i][j] - '1'] = true;
            }
        }

        return true;
    }
};
