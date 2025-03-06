class TrieNode {
public:
    vector<TrieNode*> next;
    bool isRoot;
    TrieNode(): next(26), isRoot(false) {}
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode root;
        for (string& d : dictionary) {
            auto p = &root;
            for (char& c : d) {
                if (!p->next[c - 'a'])
                    p->next[c - 'a'] = new TrieNode();
                p = p->next[c - 'a'];
            }
            p->isRoot = true;
        }
        
        istringstream iss(sentence);
        string res, w;
        while (iss >> w) {
            bool found = false;
            auto p = &root;
            int i;
            for (i = 0; i < w.size() && !found; ++i) {
                if (!p->next[w[i] - 'a']) break;
                p = p->next[w[i] - 'a'];
                if (p->isRoot)
                    found = true;
            }
            if (found)
                res += w.substr(0, i) + " ";
            else
                res += w + " ";
        }
        
        res.pop_back();
        return res;
    }
};
