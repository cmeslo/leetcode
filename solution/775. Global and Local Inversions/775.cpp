class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n = A.size();
        int mx = INT_MIN;
        for (int i = 0; i < n - 2; ++i) {
            mx = max(mx, A[i]);
            if (mx > A[i + 2]) return false;
        }
        return true;
    }
};
