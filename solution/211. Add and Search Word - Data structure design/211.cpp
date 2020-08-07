class TrieNode {
public:
    vector<TrieNode*> childs;
    const string* word;
    
    TrieNode(): childs(26), word(nullptr) {};
    ~TrieNode() {
        for (auto* child : childs)
            delete child;
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool search(string& word, TrieNode* node, int s) {
        auto* cur = node;
        for (int i = s; i < word.length(); i++) {
            if (word[i] != '.') {
                const auto& child = cur->childs[word[i] - 'a'];
                if (!child) return false;
                cur = child;
            } else {
                for (int j = 0; j < 26; j++) {
                    const auto& child = cur->childs[j];
                    if (child && search(word, child, i+1)) return true;
                }
                return false;
            }
        }
        return cur->word ? true : false;
    }
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto* cur = root;
        for (const char& c : word) {
            auto& child = cur->childs[c - 'a'];
            if (!child) child = new TrieNode();
            cur = child;
        }
        cur->word = &word;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
