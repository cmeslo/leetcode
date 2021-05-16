# 820. Short Encoding of Words

## Solution 1 - 構建逆向Trie，然後找葉子

### 寫法一

```cpp
class TrieNode {
public:
    vector<TrieNode*> childs;
    const string* word;
    
    TrieNode(): childs(26), word(nullptr) {};
    ~TrieNode() {
        for (auto child : childs)
            delete child;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode root;
        for (auto& word : words) {
            auto cur = &root;
            for (int i = word.size() - 1; i >= 0; --i) {
                auto& child = cur->childs[word[i] - 'a'];
                if (!child) child = new TrieNode();
                cur = child;
            }
            cur->word = &word;
        }
        
        int ans = 0;
        queue<TrieNode*> q;
        q.push(&root);
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            bool isLeaf = true;
            for (auto child : node->childs) {
                if (child) {
                    q.push(child);
                    isLeaf = false;
                }
            }
            if (isLeaf)
                ans += (*node->word).length() + 1;
        }
        return ans;
    }
};
```

### 寫法二

這樣找葉子會方便一點

```cpp
// Your runtime beats 38.86 % of cpp submissions.

class TrieNode {
public:
    unordered_map<char, TrieNode*> next;
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode root;
        
        vector<pair<TrieNode*, int>> leaves; // {TrieNode*, length}
        
        for (auto& word : unordered_set<string>(begin(words), end(words))) {
            auto cur = &root;
            for (int i = word.size() - 1; i >= 0; --i) {
                if (!cur->next.count(word[i]))
                    cur->next[word[i]] = new TrieNode;
                cur = cur->next[word[i]];
            }
            leaves.push_back({cur, word.size()});
        }
        
        int ans = 0;
        for (auto [node, len] : leaves)
            if (node->next.size() == 0)
                ans += len + 1;
        
        return ans;
    }
};
```

## Solution 2 - 暴力刪走所有結尾子字符串

```cpp
// Your runtime beats 81.25 % of cpp submissions.

int minimumLengthEncoding(vector<string>& words) {
    unordered_set<string> s(begin(words), end(words));

    for (auto word : s)
        for (int i = 1; i < word.size(); ++i)
            s.erase(word.substr(i));

    int ans = 0;
    for (auto word : s)
        ans += word.size() + 1;
    return ans;
}
```

## Solution 3 - 俄羅斯套公仔

```cpp
// Your runtime beats 95.89 % of cpp submissions.
// Your memory usage beats 91.78 % of cpp submissions.

int minimumLengthEncoding(vector<string>& words) {
    for (auto& word : words)
        reverse(begin(word), end(word));

    sort(begin(words), end(words));

    int ans = 0;
    for (int i = 0; i < words.size() - 1; ++i) {
        if (words[i] == words[i + 1].substr(0, words[i].size())) // 能夠套進去，就跳過
            continue;
        ans += words[i].size() + 1;
    }
    ans += words.back().size() + 1;
    return ans;
}
```
