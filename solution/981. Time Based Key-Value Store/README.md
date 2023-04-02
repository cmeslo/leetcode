# 981. Time Based Key-Value Store

```cpp
class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (!m.count(key)) return "";
        
        auto it = m[key].upper_bound(timestamp);
        if (it == m[key].begin()) return "";
        
        return prev(it)->second;
    }
    
private:
    unordered_map<string, map<int, string>> m;
};
```
