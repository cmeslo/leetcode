class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
		int total = 0;
		for (int i = 0; i < 32; ++i) {
			int one = 0;
			for (int num : nums) {
				if (num & (1 << i)) one++;
			}
			total += one * (n - one); // (one's count) * (zero's count) for every column's hamming distance
		}
		return total;
    }
};