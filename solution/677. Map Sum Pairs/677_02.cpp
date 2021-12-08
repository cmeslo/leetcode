class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
    }
    
    void insert(string key, int val) {
        int inc = val - vals_[key];
        for (int l = 1; l <= key.length(); ++l)
            sums_[key.substr(0, l)] += inc;
        vals_[key] = val;
    }
    
    int sum(string prefix) {
        return sums_[prefix];
    }
    
private:
    unordered_map<string, int> vals_;
    unordered_map<string, int> sums_;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
