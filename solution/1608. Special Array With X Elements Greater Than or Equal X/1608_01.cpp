class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        for (int i = 1; i <= n; ++i) {
            int cnt = 0;
            for (int x : nums) {
                cnt += x >= i;
            }
            if (cnt == i)
                return cnt;
        }
        return -1;
    }
};
