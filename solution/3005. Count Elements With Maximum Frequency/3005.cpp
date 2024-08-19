class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> f(101);
        int mx = 0, res = 0;
        for (int x : nums) {
            mx = max(mx, ++f[x]);
        }
        for (int x : nums) {
            if (f[x] == mx)
                ++res;
        }
        return res;
    }
};
