# 79. Word Search

## Solution: DFS

```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0] && dfs(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
    
private:
    const vector<int> dirs = {0, -1, 0, 1, 0};
    int m, n;
    
    bool dfs(vector<vector<char>>& board, const string& word, int pos, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[pos]) return false;
        if (pos == word.size() - 1) return true;
        
        char c = board[i][j];
        board[i][j] = '#';
        for (int k = 0; k < 4; ++k) {
            int y = i + dirs[k];
            int x = j + dirs[k + 1];
            if (dfs(board, word, pos + 1, y, x))
                return true;
        }
        board[i][j] = c;
        
        return false;
    } 
};
```
