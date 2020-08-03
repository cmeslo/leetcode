# 705. Design HashSet

題目定為Easy，再看看數字長度要求，應該不是要求實現一個真的```set```

## 一組數組
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

## 二組數組，利用hash 節省一點空間

插入相應數字時才分配空間

```cpp
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        data.resize(1000, vector<int>());
    }
    
    void add(int key) {
        int hashkey = key / 1000;
        if (data[hashkey].empty()) {
            data[hashkey].resize(1000, 0);
        }
        data[hashkey][key % 1000] = 1;
    }
    
    void remove(int key) {
        int hashkey = key / 1000;
        if (data[hashkey].empty()) return;
        data[hashkey][key % 1000] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hashkey = key / 1000;
        if (data[hashkey].empty()) return false;
        return data[hashkey][key % 1000];
    }

private:
    vector<vector<int>> data;
};
```
