class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for (int x : arr)
            ++m[x];
        
        if (k == 0)
            return m.size();
        
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            return m[a] < m[b] || (m[a] == m[b] && a < b);
        });
        
        for (int x : arr) {
            if (--m[x] == 0)
                m.erase(x);
            if (--k == 0)
                break;
        }
        return m.size();
    }
};
