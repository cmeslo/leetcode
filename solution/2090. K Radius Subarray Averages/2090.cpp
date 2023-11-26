class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> res(n, -1);
        int len = k + k;
        long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (i >= len) {
                res[i - k] = sum / (len + 1);
                sum -= nums[i - len];
            }
        }
        return res;
    }
};
