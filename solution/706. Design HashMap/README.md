# 706. Design HashMap

## 由於數據規模不大，所以可以暴力解：

```cpp
// Your runtime beats 66.99 % of cpp submissions.
// Your memory usage beats 29.75 % of cpp submissions.

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        keys_.resize(1e6, -1);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        keys_[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return keys_[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        keys_[key] = -1;
    }
    
private:
    vector<int> keys_;
};
```

## 好一點的方法，vector + list：

```cpp
// Your runtime beats 85.10 % of cpp submissions.
// Your memory usage beats 62.24 % of cpp submissions.

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
```
