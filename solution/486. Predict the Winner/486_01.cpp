class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
		vector<vector<int>> memo(nums.size(), vector<int> (nums.size()));
		return score(nums, 0, nums.size() - 1, memo) >= 0;
	}

	int score(vector<int>& nums, int s, int e, vector<vector<int>>& memo) {
		if (memo[s][e] != NULL) return memo[s][e];
		if (s == e) return nums[s];

		int a = nums[s] - score(nums, s + 1, e, memo);
		int b = nums[e] - score(nums, s, e - 1, memo);

		memo[s][e] = max(a, b);
		return memo[s][e];
	}
};
