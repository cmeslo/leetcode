class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int x : nums)
            m[x]++;
        
        int res = 0;
        for (auto& [x, count] : m) {
            if ((k == 0 && count > 1) || (k > 0 && m.count(x + k)))
                res++;
        }
        return res;
    }
};
