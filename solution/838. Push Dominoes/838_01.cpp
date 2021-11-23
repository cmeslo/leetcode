class Solution {
public:
    string pushDominoes(string D) {
        int n = D.size();
        
        // push R...L
        for (int i = 0; i < n; ++i) {
            if (D[i] == 'R') {
                while (i + 1 < n && D[i + 1] == 'R') ++i;
                int l = i, r = i + 1;
                for (r = i + 1; r < n && D[r] == '.'; ++r);
                i = r - 1;
                if (r >= n || D[r] != 'L') continue;
                while (l < r) {
                    D[l++] = 'R';
                    D[r--] = 'L';
                    if (l == r) D[l] = '#'; // case: R.L --> R#L
                }
            }
        }
        
        // push R
        for (int i = 0; i < n; ++i) {
            if (D[i] != 'R') continue;
            while (i + 1 < n && D[i + 1] == '.') {
                D[i + 1] = 'R';
                ++i;
            }
        }
        
        // push L
        for (int i = n - 1; i >= 0; --i) {
            if (D[i] != 'L') continue;
            while (i - 1 >= 0 && D[i - 1] == '.') {
                D[i - 1] = 'L';
                --i;
            }
        }
        
        for (int i = 0; i < n; ++i)
            if (D[i] == '#') D[i] = '.';
        
        return D;
    }
};

// x x x x x x R . . . . L x x x x x x
//             i         j
// x x x x x x R R . . . L x x x x x x
//               i       j
