class TrieNode {
public:
    int count;
    unordered_map<int, TrieNode*> children;
    
    TrieNode(): count(0) {}
};

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        const int n = grid.size();
        TrieNode root;
        
        for (int i = 0; i < n; ++i) {
            auto p = &root;
            for (int j = 0; j < n; ++j) {
                if (!p->children.count(grid[i][j]))
                    p->children[grid[i][j]] = new TrieNode();
                p = p->children[grid[i][j]];
            }
            p->count++;
        }
        
        int res = 0;
        for (int j = 0; j < n; ++j) {
            auto p = &root;
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                if (!p->children.count(grid[i][j])) {
                    ok = false;
                    break;
                }
                p = p->children[grid[i][j]];
            }
            if (ok) res += p->count;
        }
        return res;
    }
};
