class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0;
        
        if (k == 0) {
            unordered_map<int, int> m;
            for (int n : nums)
                ++m[n];
            for (auto it : m)
                if (it.second > 1) ++ans;
            return ans;
        } else {
            unordered_set<int> s;
            for (int n : nums) {
                if (s.count(n)) continue;
                if (s.count(n - k)) ++ans;
                if (s.count(n + k)) ++ans;
                s.insert(n);
            }
            return ans;
        }
    }
};
