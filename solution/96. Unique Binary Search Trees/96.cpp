class Solution {
public:
    int numTrees(int n) {
        vector<int> sum(n+1, 0);
        sum[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int root = 1; root <= i; root++) {
                sum[i] += sum[root-1] * sum[i-root];
            }
        }
        return sum[n];
    }
};
