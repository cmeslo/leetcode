class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res(m * n);
        int y = 0, x = 0;
        int dy = 0, dx = 1; // direction
        int next_y, next_x;
        for (int i = 0; i < m * n; ++i) {
            res[i] = matrix[y][x];
            matrix[y][x] = -101;
            next_y = y + dy, next_x = x + dx;
            if (next_y < 0 || next_y >= m || next_x < 0 || next_x >= n || matrix[next_y][next_x] == -101) {
                swap(dy, dx);
                dx = -dx;
            }
            y += dy, x += dx;
        }
        return res;
    }
};

// 0,0 -> 0,1 -> 0,2 -> 1,2 -> 2,2 -> 2,1 -> 2,0 -> 1,0 -> 1,1

// 0,1 ---------------> 1,0 -> 0,-1 ------> -1,0 -> 0,1 -> 

// dy,dx = dx,-dy
