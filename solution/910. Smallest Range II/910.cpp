class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(begin(A), end(A));
        
        int n = A.size();
        int mn = A[0], mx = A[n - 1];
        int ans = mx - mn;
        
        for (int i = 0; i < n - 1; ++i) {
            mn = min(A[0] + K, A[i + 1] - K);
            mx = max(A[i] + K, A[n - 1] - K);
            ans = min(ans, mx - mn);
        }
        
        return ans;
    }
};
