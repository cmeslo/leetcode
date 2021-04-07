class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int x : nums)
            ++m[x];
        
        int ans = 0;
        for (auto& [x, cnt] : m)
            if (m.count(x - 1))
                ans = max(ans, m[x - 1] + m[x]);
        
        return ans;
    }
};
