class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2, 0);
		int x = 0;
		
		for (int n : nums) x ^= n;
		
		x &= -x; // get bit 1 at the most right side
		
		for (int n : nums) {
			if (x & n) {
				ans[0] ^= n;
			} else {
				ans[1] ^= n;
			}
		}
		return ans;
    }
};