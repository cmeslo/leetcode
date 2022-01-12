class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        vector<int> rows(n), cols(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.') continue;
                int mask = 1 << (board[i][j] - '0');
                if (rows[i] & mask) return false;
                if (cols[j] & mask) return false;
                rows[i] |= mask;
                cols[j] |= mask;
            }
        }
        
        for (int i = 0; i < n; i += 3) {
            for (int j = 0; j < n; j += 3) {
                int box = 0;
                for (int y = i; y < i + 3; ++y) {
                    for (int x = j; x < j + 3; ++x) {
                        if (board[y][x] == '.') continue;
                        int mask = 1 << (board[y][x] - '0');
                        if (box & mask) return false;
                        box |= mask;
                    }
                }
            }
        }
        
        return true;
    }
};
