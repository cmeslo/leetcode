class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0;
        multiset<int> s;
        for (auto& arr : arrays)
            s.insert(arr.back());
        
        for (auto& arr : arrays) {
            auto it = s.find(arr.back());
            s.erase(it);
            res = max(res, *s.rbegin() - arr[0]);
            s.insert(arr.back());
        }
        
        return res;
    }
};
