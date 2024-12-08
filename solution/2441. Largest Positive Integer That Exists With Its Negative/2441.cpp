class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> s;
        int mx = -1;
        for (int x : nums) {
            if (x < 0) {
                s.insert(x);
            }
        }
        for (int x : nums) {
            if (x > 0) {
                if (s.count(-x)) {
                    mx = max(mx, x);
                }
            }
        }
        return mx;
    }
};
