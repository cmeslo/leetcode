class Solution {
public:
    int pivotInteger(int n) {
        int l = 1, r = n, mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            int sumL = mid * (1 + mid) / 2;
            int sumR = (n - mid + 1) * (mid + n) / 2;
            if (sumL == sumR)
                return mid;
            if (sumL < sumR)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};
