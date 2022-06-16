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

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
