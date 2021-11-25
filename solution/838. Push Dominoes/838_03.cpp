class Solution {
public:
    string pushDominoes(string D) {
        int n  = D.size();
        vector<int> L(n, n), R(n, n);
        for (int i = 0; i < n; ++i) {
            if (D[i] == 'R') {
                int cnt = 1;
                while (i + 1 < n && D[i + 1] == '.') {
                    R[i + 1] = cnt++;
                    ++i;
                }
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (D[i] == 'L') {
                int cnt =  1;
                while (i - 1 >= 0 && D[i - 1] == '.') {
                    L[i - 1] = cnt++;
                    --i;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (D[i] == '.' && L[i] != R[i])
                D[i] = L[i] < R[i] ? 'L' : 'R';
        }
        return D;
    }
};
