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

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */


// foo: 1--------4
//      bar      bar2
     
     
//          2----4
