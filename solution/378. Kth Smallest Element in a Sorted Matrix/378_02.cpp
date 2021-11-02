class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n - 1][n - 1];
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (countSmallerOrEqual(matrix, mid) < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
    
private:
    int countSmallerOrEqual(vector<vector<int>>& matrix, int val) {
        int n = matrix.size();
        int y = n - 1, x = 0;
        int cnt = 0;
        while (y >= 0 && x < n) {
            if (matrix[y][x] <= val) {
                cnt += y + 1;
                ++x;
            } else {
                --y;
            }
        }
        return cnt;
    }
};
