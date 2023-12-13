class Solution {
private:
    const vector<int> dirs = {0, -1, 0, 1, 0};
    vector<int> father;
    
    int findFather(int x) {
        if (x != father[x])
            father[x] = findFather(father[x]);
        return father[x];
    }
    
    void merge(int a, int b) {
        a = findFather(a), b = findFather(b);
        if (a == b) return;
        if (a < b)
            father[b] = a;
        else
            father[a] = b;
    }
    
public:
    int latestDayToCross(int m, int n, vector<vector<int>>& cells) {
        father.resize(m * n + 2);
        for (int i = 0; i < m * n + 2; ++i)
            father[i] = i;
        
        vector<vector<int>> G(m, vector<int>(n));
        for (auto& cell : cells) {
            int i = cell[0] - 1, j = cell[1] - 1;
            G[i][j] = 1;
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (G[i][j] == 1) continue;
                for (int k = 0; k < 4; ++k) {
                    int y = i + dirs[k];
                    int x = j + dirs[k + 1];
                    if (y < 0 || y >= m || x < 0 || x >= n || G[y][x] == 1) continue;
                    merge(i * n + j, y * n + x);
                }
            }
        }
        
        int top = m * n, bottom = m * n + 1;
        for (int j = 0; j < n; ++j) {
            merge(top, j);
            merge(bottom, (m - 1) * n + j);
        }
        
        for (int t = cells.size() - 1; t >= 0; --t) {
            if (findFather(top) == findFather(bottom))
                return t + 1;
            int i = cells[t][0] - 1;
            int j = cells[t][1] - 1;
            G[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
                int y = i + dirs[k];
                int x = j + dirs[k + 1];
                if (y < 0 || y >= m || x < 0 || x >= n || G[y][x] == 1) continue;
                merge(i * n + j, y * n + x);
            }
        }
        return 0;
    }
};
