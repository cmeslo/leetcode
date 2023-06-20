class SummaryRanges {
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        auto it = m.lower_bound(value);
        if (it != m.end() && value + 1 >= it->first) {
            m[value] = it->second;
            if (it->first != value)
                m.erase(it);
        } else {
            m[value] = value;
        }
        it = m.find(value);
        if (it != m.begin() && prev(it)->second + 1 >= value) {
            prev(it)->second = max(prev(it)->second, m[value]);
            m.erase(value);
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto& [start, end] : m) {
            res.push_back({start, end});
        }
        return res;
    }
    
private:
    map<int, int> m;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */


// prev   it
// ------ ------
//       -
//       ^
//       value
