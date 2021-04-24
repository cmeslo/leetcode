class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ans = 0, cnt = 0;
        for (int i = 2; i < A.size(); ++i) {
            cnt = (A[i - 2] - A[i - 1] == A[i - 1] - A[i]) ? cnt + 1 : 0;
            ans += cnt;
        }
        return ans;
    }
};
