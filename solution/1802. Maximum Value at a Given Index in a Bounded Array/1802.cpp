class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        int left = 0, right = maxSum, mid;
        while (left < right) {
            mid = right - (right - left) / 2;
            if (count(n, index, mid) <= maxSum)
                left = mid;
            else
                right = mid - 1;
        }
        return left + 1;
    }
    
    long count(int n, int index, int a) {
        long sum = 0;
        int b = max(a - index, 0);
        sum += 1L * (a + b) * (a - b + 1) / 2;
        b = max(a - ((n - 1) - index), 0);
        sum += 1L * (a + b) * (a - b + 1) / 2;
        return sum - a;
    }
};



// x x x x [x] x x x
