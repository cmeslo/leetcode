# 1032. Stream of Characters

## TLE 的做法

```cpp
class TrieNode {
public:
    vector<TrieNode*> childs;
    const string* word;
    TrieNode(): childs(26), word(nullptr) {}
    ~TrieNode() {
        for (auto& child : childs)
            delete child;
    }
};

class StreamChecker {
private:
    TrieNode* root;
    set<TrieNode*> pointers;
    
public:
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        pointers.insert(root);
        for (const string& word : words) {
            auto* cur = root;
            for (const char& c : word) {
                auto& next = cur->childs[c - 'a'];
                if (!next) next = new TrieNode();
                cur = next;
            }
            cur->word = &word;
        }
    }
    
    bool query(char letter) {
        bool isFound = false;
        set<TrieNode*> tmp;
        
        for (auto& p : pointers) {
            auto* next = p->childs[letter - 'a'];
            if (next) {
                if (p != root) pointers.erase(p);
                if (next->word) isFound = true;
                tmp.insert(next);
            } else {
                if (p != root) pointers.erase(p);
            }
        }
        
        for (auto& p : tmp)
            pointers.insert(p);
        
        return isFound;
    }
};
```

## AC 的做法

關鍵是對於每一個 word，倒轉來建立 Trie

```cpp
class TrieNode {
public:
    vector<TrieNode*> childs;
    bool isWord;
    TrieNode(): childs(26), isWord(false) {}
    ~TrieNode() {
        for (auto& child : childs)
            delete child;
    }
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        _root = new TrieNode();
        _s = "";
        
        for (const string& word : words) {
            auto* cur = _root;
            for (int i = word.length() - 1; i >= 0; i--) {
                auto& next = cur->childs[word[i] - 'a'];
                if (!next) next = new TrieNode();
                cur = next;
            }
            cur->isWord = true;
        }
    }
    
    bool query(char letter) {
        _s += letter;
        
        auto* cur = _root;
        for (int i = _s.length() - 1; i >= 0; i--) {
            auto* next = cur->childs[_s[i] - 'a'];
            if (!next) return false;
            if (next->isWord) return true;
            cur = next;
        }
        return false;
    }
    
private:
    TrieNode* _root;
    string _s;
};
```
