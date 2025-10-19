class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            res += ((start >> i) ^ (goal >> i)) & 1;
        }
        return res;
    }
};
