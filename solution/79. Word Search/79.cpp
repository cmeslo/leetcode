class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        h = board.size();
        w = board[0].size();
        
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                if (walk(board, word, 0, y, x)) return true;
        
        return false;
    }
    
private:
    int h, w;
    
    bool walk(vector<vector<char>>& board, const string& word, int cur, int y, int x) {
        if (y < 0 || y == h || x < 0 || x == w || word[cur] != board[y][x]) return false;
        if (cur == word.length()-1) return true;
        
        char c = board[y][x];
        board[y][x] = '#';
        bool isFound = walk(board, word, cur+1, y+1, x)
                    || walk(board, word, cur+1, y-1, x)
                    || walk(board, word, cur+1, y, x+1)
                    || walk(board, word, cur+1, y, x-1);
        board[y][x] = c;
    
        return isFound;
    }
};
