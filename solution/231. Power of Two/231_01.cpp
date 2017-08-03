class Solution {
public:
    bool isPowerOfTwo(int n) {
		int ans = 0;
		while (n) {
			ans += (n & 1);
			n >>= 1;
			if (ans > 1) return false;
		}
		return ans == 1;
	}
};