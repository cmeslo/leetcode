#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums)
	{
		if (nums.size() == 0) return 0;
		if (nums.size() == 1) return nums[0];
		if (nums.size() == 2) return max(nums[0], nums[1]);

		int n = nums.size();

		int a = rob(nums, 1, n - 1); //assuming the first element is not being rob
		int b = rob(nums, 0, n - 2); //assuming the last element is not being rob
		return max(a, b);
	}

	int rob(vector<int>& nums, int start, int end)
	{
		//d[i] = max(d[i-1], d[i-2] + a[i])

		if (nums.size() == 0) return 0;
		if (nums.size() == 1) return nums[start];

		int prepre = nums[start];
		int pre = max(nums[start], nums[start + 1]);
		int ans = pre;

		for (int i = start + 2; i <= end; ++i) {
			int cur = max(pre, prepre + nums[i]);
			ans = max(ans, cur);
			prepre = pre;
			pre = cur;
		}
		return ans;
	}
};

void main()
{
	auto ans = new Solution;

	vector<int> test = {1, 2, 3, 4, 5};
	cout << ans->rob(test) << endl;
}