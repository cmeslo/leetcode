# 211. Add and Search Word - Data structure design

## Solution: Trie

```cpp
class TrieNode {
public:
    vector<TrieNode*> next;
    bool isWord;
    TrieNode(): next(26), isWord(false) {};
};

class WordDictionary {
public:
    WordDictionary() {
    }
    
    void addWord(string word) {
        auto cur = &root;
        for (char& c : word) {
            auto& child = cur->next[c - 'a'];
            if (!child)
                child = new TrieNode();
            cur = child;
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        return dfs(&root, 0, word);
    }
    
private:
    TrieNode root;
    
    bool dfs(TrieNode* node, int i, const string& word) {
        if (!node) return false;
        
        if (i == word.size())
            return node->isWord;
        
        if (word[i] != '.')
            return dfs(node->next[word[i] - 'a'], i + 1, word);
        
        for (auto child : node->next)
            if (dfs(child, i + 1, word))
                return true;
        
        return false;
    }
};
```

### 加 cache 提速:

```cpp
class TrieNode {
public:
    vector<TrieNode*> next;
    bool is_word;
    TrieNode(): next(26), is_word(false) {}
};

class WordDictionary {
public:
    WordDictionary() {
    }
    
    void addWord(string word) {
        auto p = &root;
        for (const char& c : word) {
            int i = c - 'a';
            if (!p->next[i])
                p->next[i] = new TrieNode;
            p = p->next[i];
        }
        p->is_word = true;
        mem.clear();
    }
    
    bool search(string word) {
        if (mem.count(word)) return mem[word];
        return mem[word] = dfs(&root, 0, word);
    }
    
private:
    TrieNode root;
    unordered_map<string, bool> mem;
    
    bool dfs(TrieNode* p, int i, const string& word) {
        if (!p) return false;
        
        if (i == word.size())
            return p->is_word;
        
        if (word[i] != '.')
            return dfs(p->next[word[i] - 'a'], i + 1, word);
        
        for (auto nxt : p->next)
            if (dfs(nxt, i + 1, word))
                return true;
        
        return false;
    }
};
```
