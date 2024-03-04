class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> A(s.begin(), s.end());
        sort(A.begin(), A.end());

        int res = n, j = 0;
        for (int i = 0; i < A.size(); ++i) {
            while (j < A.size() && (A[j] - A[i] + 1 <= n)) {
                res = min(res, n - (j - i + 1));
                j++;
            }
        }
        return res;
    }
};
