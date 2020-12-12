class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        
        int ans = 0;
        int inc = 0, dec = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (dec && A[i] < A[i + 1] || A[i] == A[i + 1])
                inc = dec = 0;
            
            inc += A[i] < A[i + 1];
            dec += A[i] > A[i + 1];
            
            if (inc && dec)
                ans = max(ans, inc + 1 + dec);
        }
        
        return ans;
    }
};
