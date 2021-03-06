class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt = 0;
        while (n) {
            cnt += (n & 1);
            if (cnt > 1) return false;
            n >>= 1;
        }
        return cnt == 1;
    }
};
