#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		return bfs(nums, 0, nums.size() -1, 1) >= 0;
	}

	int bfs(vector<int>& nums, int left, int right, int turn) {
		if (left == right) {
			return turn * nums[left];
		}

		int a = turn * nums[left] + bfs(nums, left + 1, right, -turn);
		int b = turn * nums[right] + bfs(nums, left, right - 1, -turn);

		return turn * max(turn * a, turn * b);
	}
};

void main()
{
	auto ans = new Solution;
	vector<int> nums = { 1, 5, 2 };

	cout << ans->PredictTheWinner(nums) << endl;
}