class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int x : arr) ++m[x];
        
        vector<int> keys;
        for (auto it : m)
            keys.push_back(it.first);
        
        sort(keys.begin(), keys.end(), [&](int a, int b) {
            return abs(a) < abs(b);
        });
        
        for (int x : keys) {
            if (m[x] > m[x * 2])
                return false;
            m[x * 2] -= m[x];
        }
        return true;
    }
};
