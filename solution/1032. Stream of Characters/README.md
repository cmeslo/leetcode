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

## Solution: Trie

關鍵是對於每一個 word，倒轉來建立 Trie

```cpp
class TrieNode {
public:
    vector<TrieNode*> next;
    bool isWord;
    TrieNode(): next(26), isWord(false) {}
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        for (const string& word : words) {
            auto cur = &root;
            for (int i = word.size() - 1; i >= 0; --i) {
                int j = word[i] - 'a';
                if (!cur->next[j])
                    cur->next[j] = new TrieNode();
                cur = cur->next[j];
            }
            cur->isWord = true;
        }
    }
    
    bool query(char letter) {
        stream.push_back(letter - 'a');
        auto cur = &root;
        for (int i = stream.size() - 1; i >= 0; --i) {
            cur = cur->next[stream[i]];
            if (!cur) return false;
            if (cur->isWord) return true;
        }
        return false;
    }

private:
    TrieNode root;
    vector<int> stream;
};
```
