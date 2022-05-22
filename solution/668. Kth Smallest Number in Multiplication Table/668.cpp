class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (countSmallerOrEqual(m, n, mid) < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
    
    int countSmallerOrEqual(int m, int n, int val) {
        int cnt = 0;
        int y = m, x = 1;
        while (y > 0 && x <= n) {
            if (y * x <= val) {
                cnt += y;
                ++x;
            } else {
                --y;
            }
        }
        return cnt;
    }
};
