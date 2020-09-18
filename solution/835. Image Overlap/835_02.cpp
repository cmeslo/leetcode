class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        return max(shift_count(A, B), shift_count(B, A));
    }
    
private:
    int shift_count(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size(), count = 0;
        
        for (int y = 0; y < n; ++y)
            for (int x = 0; x < n; ++x) {
                int temp = 0;
                for (int i = y; i < n; ++i)
                    for (int j = x; j < n; ++j)
                        if (A[i][j] == 1 && B[i-y][j-x] == 1) temp++;
                count = max(count, temp);
            }
        
        return count;
    }
};
