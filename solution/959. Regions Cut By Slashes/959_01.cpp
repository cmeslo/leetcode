class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        const int m = grid.size(), n = grid[0].size();
        
        int len = ((m - 1) * n + (n - 1) + 1) * 2;
        father.resize(len);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int a = (i * n + j) * 2;
                int b = a + 1;
                if (grid[i][j] == '/') {
                    father[a] = a;
                    father[b] = b;
                    mergeNeighbor(grid, i, j);
                } else if (grid[i][j] == '\\') {
                    father[a] = a;
                    father[b] = b;
                    mergeNeighbor(grid, i, j);
                } else {
                    father[a] = father[b] = a;
                    mergeNeighbor(grid, i, j);
                }
            }
        }
        
        unordered_set<int> s;
        for (int i = 0; i < len; ++i) {
            s.insert(findFather(i));
        }
        
        return s.size();
    }
    
private:
    vector<int> father;
    
    void merge(int a, int b) {
        a = findFather(a), b = findFather(b);
        if (a == b) return;
        if (a < b)
            father[b] = a;
        else
            father[a] = b;
    }
    
    int findFather(int x) {
        if (x != father[x])
            father[x] = findFather(father[x]);
        return father[x];
    }
    
    void mergeNeighbor(vector<string>& grid, int i, int j) {
        const int m = grid.size(), n = grid[0].size();
        
        int idx = i * n + j;
        int a = idx * 2, b = idx * 2 + 1;
        // merge up
        if (i - 1 >= 0) {
            int up_a = ((i - 1) * n + j) * 2;
            int up_b = up_a + 1;
            
            if (grid[i][j] == '/' && grid[i - 1][j] == '/') {
                merge(a, up_b);
            } else if (grid[i][j] == '/' && grid[i - 1][j] == '\\') {
                merge(a, up_a);
            } else if (grid[i][j] == '/' && grid[i - 1][j] == ' ') {
                merge(a, up_a);
            } else if (grid[i][j] == '\\' && grid[i - 1][j] == '\\') {
                merge(b, up_a);
            } else if (grid[i][j] == '\\' && grid[i - 1][j] == '/') {
                merge(b, up_b);
            } else if (grid[i][j] == '\\' && grid[i - 1][j] == ' ') {
                merge(b, up_a);
            } else if (grid[i][j] == ' ' && grid[i - 1][j] == '/') {
                merge(a, up_b);
            } else if (grid[i][j] == ' ' && grid[i - 1][j] == '\\') {
                merge(a, up_a);
            } else if (grid[i][j] == ' ' && grid[i - 1][j] == ' ') {
                merge(a, up_a);
            }
        }
        
//         // merge bottom
//         if (i + 1 < m) {
//             int down_a = ((i + 1) * n + j) * 2;
//             int down_b = down_a + 1;
            
//             if (grid[i][j] == '/' && grid[i + 1][j] == '/') {
//                 merge(b, down_a);
//             } else if (grid[i][j] == '/' && grid[i + 1][j] == '\\') {
//                 merge(b, down_b);
//             } else if (grid[i][j] == '/' && grid[i + 1][j] == ' ') {
//                 merge(b, down_a);
//             } else if (grid[i][j] == '\\' && grid[i + 1][j] == '\\') {
//                 merge(a, down_b);
//             } else if (grid[i][j] == '\\' && grid[i + 1][j] == '/') {
//                 merge(a, down_a);
//             } else if (grid[i][j] == '\\' && grid[i + 1][j] == ' ') {
//                 merge(a, down_a);
//             } else if (grid[i][j] == ' ' && grid[i + 1][j] == '/') {
//                 merge(a, down_a);
//             } else if (grid[i][j] == ' ' && grid[i + 1][j] == '\\') {
//                 merge(a, down_b);
//             } else if (grid[i][j] == ' ' && grid[i + 1][j] == ' ') {
//                 merge(a, down_a);
//             }
//         }
        
        // merge left
        if (j - 1 >= 0) {
            int left_a = (i * n + (j - 1)) * 2;
            int left_b = left_a + 1;
            merge(a, left_b);
        }
        
        // // merge right
        // if (j + 1 < n) {
        //     int right_a = (i * n + (j + 1)) * 2;
        //     int right_b = right_a + 1;
        //     merge(b, right_a);
        // }
    }
};
