class MyHashMap {
private:
    vector<list<pair<int, int>>> data_;
    size_t size_ = 10000;

public:
    /** Initialize your data structure here. */
    MyHashMap() {
        data_.resize(size_);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto& l = data_[key % size_];
        for (auto& [k, v] : l) {
            if (k == key) {
                v = value;
                return;
            }
        }
        l.emplace_back(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto& l = data_[key % size_];
        for (auto& [k, v] : l)
            if (k == key)
                return v;
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto& l = data_[key % size_];
        for (auto it = l.begin(); it != l.end(); ++it) {
            if (it->first == key) {
                l.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
