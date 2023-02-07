class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = INT_MIN;
        
        if (m > n) {
            vector<vector<int>> matrix2(vector<vector<int>>(n, vector<int>(m)));
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                    matrix2[j][i] = matrix[i][j];
            return maxSumSubmatrix(matrix2, k);
        }
        
        for (int y1 = 0; y1 < m; ++y1) {
            vector<int> compressed(n);
            for (int y2 = y1; y2 < m; ++y2) {
                int sum = 0;
                set<int> s{0};
                for (int x = 0; x < n; ++x) {
                    compressed[x] += matrix[y2][x];
                    sum += compressed[x];
                    auto it = s.lower_bound(sum - k);
                    if (it != s.end()) ans = max(ans, sum - *it);
                    s.insert(sum);
                }
            }
        }
        return ans;
    }
};


//  x x x x x x x x
// [x x x x x x x x  y1
//  x x x x x x x x
//  x x x x x x x x] y2
//  x x x x x x x x

//  Y Y [Y Y Y Y] Y Y --> sums from y1 to y2 <= k
//    i        j

// prefix[j] - prefix[i] <= k
// prefix[i] >= prefix[j] - k


