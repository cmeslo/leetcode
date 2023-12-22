class Solution {
public:
    long long putMarbles(vector<int>& W, int k) {
        using ll = long long;
        const int n = W.size();
        
        vector<ll> A;
        for (int i = 1; i < n; ++i) {
            A.push_back(W[i - 1] + W[i]);
        }
        
        sort(begin(A), end(A));
        
        ll res = 0;
        for (int i = 0; i < k - 1; ++i) {
            res += A[A.size() - 1 - i];
            res -= A[i];
        }
        return res;
    }
};

// x x  x | x  x | x x x
// x x [x | x] x | x x x
