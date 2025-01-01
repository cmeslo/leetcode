class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int k) {
        const int n = A.size();
        int a = 0, b = 0;
        
        double l = 0, r = 1, m;
        while (l < r) {
            m = l + (r - l) / 2;
            
            double fmax = 0;
            int cnt = 0;
            for (int i = 0, j = 0; i < n; ++i) {
                while (j < n && A[i] > m * A[j]) ++j;
                cnt += n - j;
                if (n == j) break;
                double f = A[i] * 1.0 / A[j];
                if (f > fmax) {
                    fmax = f;
                    a = i, b = j;
                }
            }
            
            if (cnt == k)
                return {A[a], A[b]};
            else if (cnt < k)
                l = m;
            else
                r = m;
        }
        return {};
    }
};
