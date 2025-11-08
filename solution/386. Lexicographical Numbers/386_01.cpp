class TrieNode {
public:
    vector<TrieNode*> next;
    int num;
    TrieNode(): next(10), num(-1) {}
};

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        TrieNode root;
        for (int i = 1; i <= n; ++i) {
            string x = to_string(i);
            auto p = &root;
            for (char& c : x) {
                auto& nxt = p->next[c - '0'];
                if (!nxt)
                    nxt = new TrieNode();
                p = nxt;
            }
            p->num = i;
        }
        
        vector<int> res;
        for (auto nxt : root.next)
            dfs(nxt, res);
        return res;
    }
    
private:
    void dfs(TrieNode* p, vector<int>& res) {
        if (!p) return;
        res.push_back(p->num);
        
        for (auto& nxt : p->next)
            dfs(nxt, res);
    }
};
