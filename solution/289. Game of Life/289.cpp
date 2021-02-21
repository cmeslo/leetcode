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
                    board[y][x] |= (1 << 1);
            }
        }
        
        for (int y = 0; y < h; ++y)
            for (int x = 0; x < w; ++x)
                board[y][x] >>= 1;
    }
};
