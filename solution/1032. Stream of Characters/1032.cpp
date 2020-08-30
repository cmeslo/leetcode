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

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
