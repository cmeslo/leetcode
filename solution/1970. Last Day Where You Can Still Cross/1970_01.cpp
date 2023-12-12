class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 0, r = cells.size(), m;
        while (l < r) {
            m = r - (r - l) / 2;
            if (checkOK(row, col, cells, m))
                l = m;
            else
                r = m - 1;
        }
        return l;
    }
    
    const vector<int> dirs = {0, -1, 0, 1, 0};
    
    bool checkOK(int row, int col, vector<vector<int>>& cells, int limit) {
        vector<vector<int>> A(row, vector<int>(col));
        for (int i = 0; i < limit; ++i) {
            int y = cells[i][0] - 1, x = cells[i][1] - 1;
            A[y][x] = 1;
        }
        
        queue<pair<int, int>> q;
        for (int j = 0; j < col; ++j) {
            if (A[0][j] == 1) continue;
            A[0][j] = 2;
            q.push({0, j});
        }
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            if (i == row - 1) return true;
            for (int k = 0; k < 4; ++k) {
                int y = i + dirs[k];
                int x = j + dirs[k + 1];
                if (y < 0 || y >= row || x < 0 || x >= col || A[y][x] != 0) continue;
                A[y][x] = 2;
                q.push({y, x});
            }
        }
        return false;
    }
};
