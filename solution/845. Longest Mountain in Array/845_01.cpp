class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        vector<int> increasing(n), decreasing(n);
        
        for (int i = 1; i < n; ++i)
            if (A[i - 1] < A[i]) increasing[i] = increasing[i - 1] + 1;
        
        for (int i = n - 2; i >= 0; --i)
            if (A[i] > A[i + 1]) decreasing[i] = decreasing[i + 1] + 1;
        
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (increasing[i] && decreasing[i])
                ans = max(ans, increasing[i] + 1 + decreasing[i]);
        
        return ans;
    }
};
