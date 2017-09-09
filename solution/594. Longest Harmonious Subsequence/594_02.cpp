class Solution {
public:
    int findLHS(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int maxLen = 0;
        map<int, int> m;
        
        for (int n : nums) ++m[n];
        
        for (auto a : m) {
            if (m.count(a.first + 1)) {
                maxLen = max(maxLen, m[a.first] + m[a.first + 1]);
            }
        }
        return maxLen;
    }
};
