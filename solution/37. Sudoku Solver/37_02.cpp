class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        rows.resize(n), cols.resize(n), boxes.resize(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.') continue;
                int mask = 1 << (board[i][j] - '0');
                rows[i] |= mask;
                cols[j] |= mask;
                boxes[i / 3 * 3 + j / 3] |= mask;
            }
        }
        
        dfs(board, 0, 0);
    }
    
private:
    int n = 9;
    vector<int> rows, cols, boxes;
    
    bool dfs(vector<vector<char>>& board, int y, int x) {
        if (y == n) return true;
        if (x == n) return dfs(board, y + 1, 0);
        if (board[y][x] != '.') return dfs(board, y, x + 1);
        
        int boxIndex = y / 3 * 3 + x / 3;
        for (int k = 1; k <= 9; ++k) {
            int mask = 1 << k;
            if ((rows[y] & mask) != 0 || (cols[x] & mask) != 0 || (boxes[boxIndex] & mask) != 0)
                continue;
            rows[y] |= mask;
            cols[x] |= mask;
            boxes[boxIndex] |= mask;
            board[y][x] = k + '0';
            if (dfs(board, y, x + 1)) return true;
            board[y][x] = '.';
            rows[y] ^= mask;
            cols[x] ^= mask;
            boxes[boxIndex] ^= mask;
        }
        return false;
    }
};
