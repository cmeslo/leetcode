class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        const int n = grid.size();
        int res = 0;
        unordered_map<string, int> row;
        for (int i = 0; i < n; ++i) {
            string r = "";
            for (int j = 0; j < n; ++j) {
                r += to_string(grid[i][j]) + "-";
            }
            row[r]++;
        }
        for (int j = 0; j < n; ++j) {
            string c = "";
            for (int i = 0; i < n; ++i) {
                c += to_string(grid[i][j]) + "-";
            }
            if (row.count(c)) {
                res += row[c];
            }
        }
        return res;
    }
};
