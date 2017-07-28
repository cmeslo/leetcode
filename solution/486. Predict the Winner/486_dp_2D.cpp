#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));

		for (int s = n - 1; s >= 0; --s) {
			for (int e = s + 1; e < n; ++e) {
				int a = nums[s] - dp[s + 1][e];
				int b = nums[e] - dp[s][e - 1];
				dp[s][e] = max(a, b);
			}
		}
		return dp[0][n - 1] >= 0;
	}
};

void main()
{
	auto ans = new Solution;
	vector<int> nums = { 1, 5, 2 };

	cout << ans->PredictTheWinner(nums) << endl;

}