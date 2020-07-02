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
