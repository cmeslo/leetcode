class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        
        for (int n : nums)
            ++m[n];
        
        int ans = 0;
        for (auto it : m)
            if ((k == 0 && it.second > 1) || (k > 0 && m.count(it.first + k)))
                ++ans;
        
        return ans;
    }
};
