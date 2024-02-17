class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        customers = '#' + customers + '#';
        vector<int> L(n + 2), R(n + 2);
        for (int i = 1; i <= n + 1; ++i) {
            L[i] = L[i - 1];
            if (customers[i - 1] == 'N')
                L[i]++;
        }
        for (int i = n; i >= 0; --i) {
            R[i] = R[i + 1];
            if (customers[i + 1] == 'Y')
                R[i]++;
        }
        int res = 0, mn = INT_MAX;
        for (int i = 0; i <= n + 1; ++i) {
            if (L[i] + R[i] < mn) {
                mn = L[i] + R[i];
                res = i;
            }
        }
        return res;
    }
};

// # Y Y N Y #
// 0 1 2 3 4 5
