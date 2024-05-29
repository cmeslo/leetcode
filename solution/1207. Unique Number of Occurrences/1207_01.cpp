class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int x : arr)
            ++m[x];
        
        unordered_set<int> s;
        int res = 0;
        for (auto& [k, v] : m) {
            if (s.count(v))
                return false;
            s.insert(v);
        }
        return true;
    }
};
