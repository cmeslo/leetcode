class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int n : nums)
            if (n < k) ++m[n];
        
        int ans = 0;
        for (auto& [x, cnt] : m) {
            if (m.find(k - x) == m.end()) continue;
            if (k - x == x) {
                // if (cnt == 1) continue;
                ans += cnt / 2;
                // cnt = cnt % 2 ? 1 : 0;
            } else {
                int pairs = min(cnt, m[k - x]);
                m[k - x] -= pairs;
                cnt -= pairs;
                ans += pairs;
            }
        }
        
        return ans;
    }
};
