class Solution {
public:
    int largestVariance(string s) {
        int n = s.size();
        
        vector<bool> exists(26, false);
        for (char& c : s)
            exists[c - 'a'] = true;
        
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (!exists[i] || !exists[j]) continue;
                if (i == j) continue;
                
                vector<int> A(n, 0);
                for (int k = 0; k < n; ++k) {
                    if (s[k] - 'a' == i)
                        A[k] = 1;
                    else if (s[k] - 'a' == j)
                        A[k] = -1;
                }
                
                res = max(res, count(A));
            }
        }
        return res;
    }
    
    int count(vector<int>& A) {
        int n = A.size();
        vector<int> dp1(n);
        dp1[0] = A[0];
        for (int i = 1; i < n; ++i) {
            dp1[i] = max(dp1[i - 1] + A[i], A[i]);
        }
        
        int res = 0;
        int curSum = 0;
        for (int i = n - 1; i >= 0; --i) {
            curSum = max(curSum + A[i], A[i]);
            if (A[i] == -1)
                res = max(res, dp1[i] + curSum - A[i]);
        }
        return res;
    }
};


// a  a  b  a  b  b  b
// 1  1 -1  1 -1 -1 -1
    
    
// -1 [-1 {-1] 1 x x} x
