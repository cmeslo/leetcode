class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();
        // 1. check columns, it can only have two patterns.
        int cnt1 = 1;
        for (int j = 1; j < n; ++j) {
            bool same = board[0][j] == board[0][0];
            if (same) {
                ++cnt1;
                for (int i = 1; i < n; ++i)
                    if (board[i][j] != board[i][0])
                        return -1;
            } else {
                for (int i = 1; i < n; ++i)
                    if (board[i][j] == board[i][0])
                        return -1;
            }
        }
        int cnt2 = n - cnt1;
        if (abs(cnt2 - cnt1) > 1) return -1;
        
        // 2. check rows, it can only have two patterns.
        cnt1 = 1;
        for (int i = 1; i < n; ++i) {
            bool same = board[i][0] == board[0][0];
            if (same) {
                ++cnt1;
                for (int j = 1; j < n; ++j)
                    if (board[i][j] != board[0][j])
                        return -1;
            } else {
                for (int j = 1; j < n; ++j)
                    if (board[i][j] == board[0][j])
                        return -1;
            }
        }
        cnt2 = n - cnt1;
        if (abs(cnt2 - cnt1) > 1) return -1;
        
        // 3. count diff.
        int col_diff = 0;
        for (int j = 0; j < n; ++j) {
            if (board[0][j] != j % 2)
                ++col_diff;
        }
        int row_diff = 0;
        for (int i = 0; i < n; ++i) {
            if (board[i][0] != i % 2)
                ++row_diff;
        }
        
        int res = 0;
        if (n % 2 == 0) {
            res += min(col_diff, n - col_diff) / 2;
            res += min(row_diff, n - row_diff) / 2;
        } else {
            if (col_diff % 2) col_diff = n - col_diff;
            if (row_diff % 2) row_diff = n - row_diff;
            res += col_diff / 2;
            res += row_diff / 2;
        }
        return res;
    }
};

// 最後要特別留意 n 是奇數的情況
// 110
// 101 -> diff = 2
// 010 -> diff = 1，但 110 不可能變出 010，只能是 101

// mismatch，需要換位的、必定是偶數
