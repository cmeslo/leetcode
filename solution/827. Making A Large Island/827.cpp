class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        g_ = &grid;
        m_ = grid.size(), n_ = grid[0].size();
        color_ = 2;
        unordered_map<int, int> areas;
        
        int ans = 0;
        for (int i = 0; i < m_; ++i) {
            for (int j = 0; j < n_; ++j) {
                if (grid[i][j] == 1) {
                    areas[color_] = get_area(i, j);
                    ans = max(ans, areas[color_]);
                    ++color_;
                }
            }
        }
        
        for (int i = 0; i < m_; ++i) {
            for (int j = 0; j < n_; ++j) {
                if (grid[i][j] == 0) {
                    int area = 1;
                    for (int color : set<int>{get_color(i + 1, j), get_color(i - 1, j),
                                              get_color(i, j + 1), get_color(i, j - 1)}) {
                        area += areas[color];
                    }
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
    
private:
    vector<vector<int>>* g_;
    int m_, n_;
    int color_;
    
    int get_area(int i, int j) {
        if (i < 0 || i >= m_ || j < 0 || j >= n_ || (*g_)[i][j] != 1) return 0;
        (*g_)[i][j] = color_;
        return 1 + get_area(i + 1, j) + get_area(i - 1, j)
                 + get_area(i, j + 1) + get_area(i, j - 1);
    }
    
    int get_color(int i, int j) {
        if (i < 0 || i >= m_ || j < 0 || j >= n_) return 0;
        return (*g_)[i][j];
    }
};
