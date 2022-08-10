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
