class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bit = 0;
		while (n) {
			if ((n >> 1) << 1 != n) {
				bit++;
			}
			n >>= 1;
		}
		return bit;
    }
};