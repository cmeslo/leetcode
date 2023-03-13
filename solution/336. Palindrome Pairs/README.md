# 336. Palindrome Pairs

```cpp
class TrieNode {
public:
    vector<TrieNode*> children;
    int wordIndex;
    vector<int> restIsPalindrome;
    
    TrieNode(): children(26), wordIndex(-1) {}
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        TrieNode root;
        
        for (int i = 0; i < n; ++i)
            add(&root, words[i], i);
        
        vector<vector<int>> res;
        for (int i = 0; i < n; ++i)
            search(&root, words[i], i, res);
        
        return res;
    }
    
private:
    void add(TrieNode* cur, const string& word, int wordIndex) {
        for (int i = word.size() - 1; i >= 0; --i) {
            int j = word[i] - 'a';
            if (isPalindrome(word, 0, i))
                cur->restIsPalindrome.push_back(wordIndex);
            if (!cur->children[j])
                cur->children[j] = new TrieNode();
            cur = cur->children[j];
        }
        cur->wordIndex = wordIndex;
    }
    
    void search(TrieNode* cur, const string& word, int wordIndex, vector<vector<int>>& ans) {
        for (int i = 0; i < word.size(); ++i) {
            int j = word[i] - 'a';
            if (cur->wordIndex != -1 && isPalindrome(word, i, word.size() - 1))
                ans.push_back({wordIndex, cur->wordIndex});
            if (!cur->children[j]) return;
            cur = cur->children[j];
        }
        
        if (cur->wordIndex != -1 && wordIndex != cur->wordIndex)
            ans.push_back({wordIndex, cur->wordIndex});
        
        for (int j : cur->restIsPalindrome)
            ans.push_back({wordIndex, j});
    }
    
    bool isPalindrome(const string& word, int i, int j) {
        while (i < j) {
            if (word[i++] != word[j--]) return false;
        }
        return true;
    }
};
```
