class Solution {
public:
    bool isPowerOfFour(int n) {
        int cnt = 0;
        if (n <= 0 || n & n-1) return false;
        
        while (n) {
            if (n == 1) return cnt%2 == 0;
            cnt += ((n & 1) == 0 ? 1 : 0);
            n >>= 1;
        }
        
        return false;
    }
};
