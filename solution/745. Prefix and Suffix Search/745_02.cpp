class TrieNode {
public:
    unordered_map<char, TrieNode*> next;
    int index;
    TrieNode(): index(-1) {};
};

class WordFilter {
public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i)
            append(words[i], i);
    }
    
    int f(string prefix, string suffix) {
        string word = suffix + '_' + prefix;
        auto cur = &root;
        for (char& c : word) {
            if (cur->next.count(c))
                cur = cur->next[c];
            else
                return -1;
        }
        return cur->index;
    }
    
private:
    TrieNode root;
    
    void append(const string& w, int index) {
        int n = w.length();
        for (int i = 0; i <= n; ++i) {
            string tmp = w.substr(n - i, i) + '_' + w;
            auto cur = &root;
            for (char& c : tmp) {
                if (!cur->next.count(c))
                    cur->next[c] = new TrieNode();
                cur = cur->next[c];
                cur->index = index;
            }
        }
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
