class MyHashSet {
private:
    vector<vector<int>> data;
    const int M = 1000;
    
public:
    MyHashSet() {
        data.resize(M);
    }
    
    void add(int key) {
        auto& a = data[key % M];
        if (a.empty())
            a.resize(M + 1, 0);
        a[key / M] = 1;
    }
    
    void remove(int key) {
        auto& a = data[key % M];
        if (a.empty()) return;
        a[key / M] = 0;
    }
    
    bool contains(int key) {
        int hash = key % M;
        auto& a = data[hash];
        if (a.empty()) return false;
        return a[key / M];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
