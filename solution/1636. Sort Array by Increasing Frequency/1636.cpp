class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> f;
        for (int x : nums) ++f[x];
        
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return f[a] < f[b] || (f[a] == f[b] && a > b);
        });
        return nums;
    }
};
