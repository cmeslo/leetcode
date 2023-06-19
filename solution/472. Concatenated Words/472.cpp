class TrieNode {
public:
    vector<TrieNode*> next;
    const string* word;
    TrieNode(): next(26), word(nullptr) {}
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        TrieNode root;
        for (string& w : words) {
            auto p = &root;
            for (char& c : w) {
                if (!p->next[c - 'a'])
                    p->next[c - 'a'] = new TrieNode();
                p = p->next[c - 'a'];
            }
            p->word = &w;
        }
        
        vector<string> res;
        for (string& w : words) {
            if (dfs(&root, w, 0, &root) > 1)
                res.push_back(w);
        }
        return res;
    }
    
private:
    int dfs(TrieNode* p, string& word, int start, TrieNode* root) {
        for (int i = start; i < word.size(); ++i) {
            auto nxt = p->next[word[i] - 'a'];
            if (!nxt) return -1;
            if (i == word.size() - 1) return nxt->word ? 1 : -1;
            if (nxt->word) {
                int tmp = dfs(root, word, i + 1, root);
                if (tmp != -1) {
                    return 1 + tmp;
                }
            }
            p = nxt;
        }
        return -1;
    }
};
