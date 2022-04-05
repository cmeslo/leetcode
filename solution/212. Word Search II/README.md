# 212. Word Search II

## Solution 1: Brute Force DFS (212_01.cpp)

對 words 裡的每一個 word，都去整個 Board 裡找一遍，

```Time complexity: O(sum(m*n*4^l))```, ```l``` 是每個 word 的長度。

另外有兩點注意：

1. board 上遍歷過的位置、將它設置為 ```#```，防止重複遍歷。
2. 用每個 word 的長度來限制 dfs 的深度，也就是剪枝，才不會超時。


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

## Solution 2: Trie + DFS (212_02.cpp)

用```Trie```來做，先用所有 word 構建出```Trie```樹，

可以只遍歷```Trie```裡存在的路徑，

可以優化處理 prefix 相同的 word。

```Time complexity: O(sum(l) + 4^max(l))```, ```l``` 是每個 word 的長度。

```cpp
class TrieNode {
public:
    vector<TrieNode*> childs;
    const string* word;
    TrieNode(): childs(26), word(nullptr) {};
    ~TrieNode() {
        for (auto node : childs) delete node;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.size() == 0) return ans;
        h = board.size(); w = board[0].size();
        
        TrieNode* root = new TrieNode();
        
        for (const string& word : words) {
            TrieNode* cur = root;
            for (char c : word) {
                auto& next = cur->childs[c - 'a']; // TrieNode*& next = cur->childs[c - 'a'];
                if (!next) next = new TrieNode();
                cur = next;
            }
            cur->word = &word;
        }
        
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                walk(board, i, j, root);
        
        return ans;
    }
    
private:
    vector<string> ans;
    int h, w;
    
    void walk(vector<vector<char>>& board, int y, int x, TrieNode* node) {
        if (y < 0 || y == h || x < 0 || x == w || board[y][x] == '#') return;
        
        const char c = board[y][x];
        TrieNode* next = node->childs[c - 'a'];
        
        if (!next) return;
        
        if (next->word) {
            ans.push_back(*next->word);
            next->word = nullptr;
        }
        
        board[y][x] = '#';
        walk(board, y+1, x, next);
        walk(board, y-1, x, next);
        walk(board, y, x+1, next);
        walk(board, y, x-1, next);
        board[y][x] = c;
    }
};
```

2022/04/05 重寫了一次：

```cpp
class TrieNode {
public:
    vector<TrieNode*> next;
    const string* word;
    
    TrieNode(): next(26, nullptr), word(nullptr) {};
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode root;
        for (string& w : words) {
            auto p = &root;
            for (char& c : w) {
                auto& next = p->next[c - 'a'];
                if (!next)
                    next = new TrieNode();
                p = next;
            }
            p->word = &w;
        }
        
        m = board.size(), n = board[0].size();
        vector<string> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, &root, i, j, ans);
            }
        }
        return ans;
    }
    
private:
    int m, n;
    const vector<int> dirs = {0, -1, 0, 1, 0};
    
    void dfs(vector<vector<char>>& board, TrieNode* p, int i, int j, vector<string>& ans) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '#') return;
        p = p->next[board[i][j] - 'a'];
        if (!p) return;
        if (p->word) {
            ans.push_back(*p->word);
            p->word = nullptr;
        }
        
        const char c = board[i][j];
        board[i][j] = '#';
        for (int k = 0; k < 4; ++k) {
            int y = i + dirs[k];
            int x = j + dirs[k + 1];
            dfs(board, p, y, x, ans);
        }
        board[i][j] = c;
    }
};
```

參考（解釋得很好）：

https://zxi.mytechroad.com/blog/searching/leetcode-212-word-search-ii/
