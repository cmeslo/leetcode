class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1e9 + 7;
        vector<int> A;
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                A.push_back(sum);
            }
        }
        sort(A.begin(), A.end());
        long res = 0;
        for (int i = left - 1; i < right; ++i)
            res = (res + A[i]) % MOD;
        return res;
    }
};
