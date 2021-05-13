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
