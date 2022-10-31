class MyHashMap {
public:
    MyHashMap() {
        m.resize(M);
    }
    
    void put(int key, int value) {
        int hash = key % M;
        if (m[hash].empty())
            m[hash].resize(M + 1, -1);
        m[hash][key / M] = value;
    }
    
    int get(int key) {
        int hash = key % M;
        if (m[hash].empty())
            return -1;
        return m[hash][key / M];
    }
    
    void remove(int key) {
        int hash = key % M;
        if (m[hash].empty())
            return;
        m[hash][key / M] = -1;
    }
    
private:
    vector<vector<int>> m;
    const int M = 1000;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
