class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        
        int ans = 0;
        for (int x : nums) {
            if (m.count(x)) continue;
            
            auto it_l = m.find(x - 1);
            auto it_r = m.find(x + 1);
            
            int l = it_l != m.end() ? it_l->second : 0;
            int r = it_r != m.end() ? it_r->second : 0;
            int len = l + 1 + r;
            
            m[x] = m[x - l] = m[x + r] = len;
            
            ans = max(ans, len);
        }
        return ans;
    }
};
