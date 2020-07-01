# 212. Word Search II

## 212_01.cpp

對 words 裡的每一個 word，都去整個 Board 裡找一遍，

```Time complexity: O(sum(m*n*4^l))```, ```l``` 是每個 word 的長度

```cpp
// Time complexity: O(sum(m*n*4^l)), which l is length of each word

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        if (board.size() == 0) return ans;
        h = board.size(); w = board[0].size();
        for (string& word : words) {
            if (exist(board, word)) ans.push_back(word);
        }
        return ans;
    }
    
private:
    int h, w;
    
    bool exist(vector<vector<char>>& board, const string& word) {
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (dfs(board, word, 0, i, j)) return true;
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, const string& word, int cur, int y, int x) {
        if (y < 0 || y == h || x < 0 || x == w || word[cur] != board[y][x]) return false; // prune
        if (cur == word.size()-1) return true;
        
        char c = board[y][x];
        board[y][x] = '#';
        bool isFound = dfs(board, word, cur+1, y+1, x)
                    || dfs(board, word, cur+1, y-1, x)
                    || dfs(board, word, cur+1, y, x+1)
                    || dfs(board, word, cur+1, y, x-1);
        board[y][x] = c;
        return isFound;
    }
};
```
