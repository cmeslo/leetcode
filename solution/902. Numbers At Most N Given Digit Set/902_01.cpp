class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string N = to_string(n);
        long res = 0, cur = 1;
        for (int i = 0; i < N.size() - 1; ++i) {
            cur *= digits.size();
            res += cur;
        }
        return res + dfs(N, digits, 0);
    }
    
    long dfs(const string& N, vector<string>& digits, int start) {
        if (start >= N.size()) return 1;
        int res = 0;
        int i = 0;
        for (; i < digits.size() && digits[i][0] < N[start]; ++i) {
            res += pow(digits.size(), N.size() - start - 1);
        }
        if (i < digits.size() && digits[i][0] == N[start]) {
            res += dfs(N, digits, start + 1);
        }
        return res;
    }
};
