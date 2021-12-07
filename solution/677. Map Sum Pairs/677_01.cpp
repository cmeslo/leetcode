class TrieNode {
public:
    vector<TrieNode*> next;
    int sum;
    TrieNode(): next(128, nullptr), sum(0) {};
    ~TrieNode() {
        for (auto child : next)
            if (child)
                delete child;
        next.clear();
    }
};

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
    }
    
    void insert(string key, int val) {
        int inc = val - m_[key];
        auto p = &root_;
        for (const char& x : key) {
            if (!p->next[x])
                p->next[x] = new TrieNode();
            p = p->next[x];
            p->sum += inc;
        }
        m_[key] = val;
    }
    
    int sum(string prefix) {
        auto p = &root_;
        for (const char& x : prefix) {
            if (!p->next[x]) return 0;
            p = p->next[x];
        }
        return p->sum;
    }
    
private:
    TrieNode root_;
    unordered_map<string, int> m_;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
