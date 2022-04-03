# 208. Implement Trie (Prefix Tree)

## Solution: Trie

```cpp
class TrieNode {
public:
    vector<TrieNode*> children;
    bool is_word;
    TrieNode(): children(26), is_word(false) {}
};

class Trie {
public:
    Trie() {
        
    }
    
    void insert(string word) {
        auto p = &root;
        for (const char& c : word) {
            int i = c - 'a';
            if (!p->children[i])
                p->children[i] = new TrieNode();
            p = p->children[i];
        }
        p->is_word = true;
    }
    
    bool search(string word) {
        auto p = &root;
        for (const char& c : word) {
            int i = c - 'a';
            if (!p->children[i]) return false;
            p = p->children[i];
        }
        return p->is_word;
    }
    
    bool startsWith(string prefix) {
        auto p = &root;
        for (const char& c : prefix) {
            int i = c - 'a';
            if (!p->children[i]) return false;
            p = p->children[i];
        }
        return true;
    }
    
private:
    TrieNode root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```
