class LRUCache {
private:
    list<int> keyList;
    unordered_map<int, pair<int, list<int>::iterator>> cache; // key -> {value, iterator}
    int capacity;
    
public:
    LRUCache(int capacity): capacity(capacity) {
        
    }
    
    int get(int key) {
        if (!cache.count(key)) return -1;
        
        auto it = cache[key].second;
        keyList.erase(it);
        keyList.push_front(key);
        cache[key].second = keyList.begin();
        
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            auto it = cache[key].second;
            keyList.erase(it);
        }
        
        keyList.push_front(key);
        cache[key] = {value, keyList.begin()};
        
        if (keyList.size() > capacity) {
            int lruKey = *keyList.rbegin();
            cache.erase(lruKey);
            keyList.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
