# 705. Design HashSet

題目定為Easy，再看看數字長度要求，應該不是要求實現一個真的```set```

## 一維數組
```cpp
class MyHashSet {
private:
    vector<int> data;
    
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        data.resize(1000000, 0);
    }
    
    void add(int key) {
        data[key] = 1;
    }
    
    void remove(int key) {
        data[key] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return data[key] == 1;
    }
};
```

## 二維數組，利用hash 節省一點空間

插入相應數字時才分配空間

```cpp
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
```
