class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
		int dist = 0;
		while (n) {
			if ((n >> 1) << 1 != n) {
				dist++;
			}
			n >>= 1;
		}
		return dist;
    }
};