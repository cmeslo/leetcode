# 289. Game of Life

## Solution 1: 複製原本的board

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

## Solution 2: In-place (289.cpp)

1. in-place，使用原本的board，每次先把答案移到 0010 的位置上，最後移回來。
2. 總結遊戲規則：```lives == 3 || (lives == 4 && board[y][x] == 1)```。


```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int h = board.size();
        int w = h ? board[0].size() : 0;
        
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                int lives = 0;
                for (int i = max(y - 1, 0); i < min(y + 2, h); ++i)
                    for (int j = max(x - 1, 0); j < min(x + 2, w); ++j)
                        lives += board[i][j] & 1;
                
                if (lives == 3 || (lives == 4 && board[y][x] == 1))
                    board[y][x] |= (1 << 1); // board[y][x] |= 0b10; <---二進制的表示法 0b，比如0b10代表 (1 << 1)
            }
        }
        
        for (int y = 0; y < h; ++y)
            for (int x = 0; x < w; ++x)
                board[y][x] >>= 1;
    }
};
```

reference: http://zxi.mytechroad.com/blog/simulation/leetcode-289-game-of-life/
