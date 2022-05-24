class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int bitA = (x >> i) & 1;
            int bitB = (y >> i) & 1;
            if (bitA != bitB)
                ++res;
        }
        return res;
    }
};
