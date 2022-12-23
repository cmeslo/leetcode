# 745. Prefix and Suffix Search

## Solution 1: Brute Force (map)

### 解釋

暴力枚舉所有可能性並放到 map 裡, 以 apple 為例：

```
_
_a
_ap
_appl
_apple
e_
e_a
e_ap
e_appl
e_apple
le_
le_a
le_ap
le_app
le_appl
le_apple
...
apple_
...
apple_apple
```

### Code

```cpp
class WordFilter {
public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            string& w = words[i];
            int n = w.size();
            vector<string> prefix(n + 1), suffix(n + 1);
            for (int j = 0; j <= n; ++j) {
                prefix[j] = w.substr(0, j);
                suffix[j] = w.substr(j, n - j);
            }
            for (string& pre : prefix)
                for (string& suf : suffix)
                    m[pre + '_' + suf] = i;
        }
        // m.erase("_");
    }
    
    int f(string prefix, string suffix) {
        auto it = m.find(prefix + '_' + suffix);
        return it == m.end() ? -1 : it->second;
    }
    
private:
    unordered_map<string, int> m;
};
```

## Solution 2: Trie

### 解釋

apple 對應要保存到 Trie 裡的 string:

```
_apple
e_apple
le_apple
ple_apple
pple_apple
apple_apple
```

另外注意，TrieNode 裡只要保存最新的 index.

### Code

```cpp
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
```
