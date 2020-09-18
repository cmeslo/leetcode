class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size(), max_count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                max_count = max(max_count, shift_count(A, B, i, j));
                max_count = max(max_count, shift_count(A, B, i, -j));
                max_count = max(max_count, shift_count(A, B, -i, j));
                max_count = max(max_count, shift_count(A, B, -i, -j));
            }
        }
        return max_count;
    }
    
private:
    int shift_count(vector<vector<int>>& A, vector<vector<int>>& B, int dirY, int dirX) {
        int n = A.size(), count = 0;
        
        for (int y = 0; y < n; ++y)
            for (int x = 0; x < n; ++x) {
                if (y + dirY < 0 || y + dirY >= n || x + dirX < 0 || x + dirX >= n)
                    continue;
                if (A[y][x] == 1 && B[y + dirY][x + dirX] == 1)
                    count++;
            }
        
        return count;
    }
};
