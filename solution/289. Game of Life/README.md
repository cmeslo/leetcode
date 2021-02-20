# 289. Game of Life

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> old_board(board);
        
        int h = board.size(), w = board[0].size();
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                int lives = countLive(old_board, y, x);
                if (old_board[y][x] == 1)
                    board[y][x] = lives < 2 || lives > 3 ? 0 : 1;
                else
                    board[y][x] = lives == 3;
            }
        }
    }

private:
    int countLive(vector<vector<int>>& board, int y, int x) {
        int h = board.size(), w = board[0].size();
        int res = 0;
        
        if (y - 1 >= 0) {
            if (x - 1 >= 0) res += board[y - 1][x - 1];
            res += board[y - 1][x];
            if (x + 1 < w) res += board[y - 1][x + 1];
        }
        if (x - 1 >= 0) res += board[y][x - 1];
        if (x + 1 < w) res += board[y][x + 1];
        if (y + 1 < h) {
            if (x - 1 >= 0) res += board[y + 1][x - 1];
            res += board[y + 1][x];
            if (x + 1 < w) res += board[y + 1][x + 1];
        }
        
        return res;
    }
};
```
