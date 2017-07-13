#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums)
	{
		//d[i] = max(d[i-1], d[i-2] + a[i])

		if (nums.size() == 0) return 0;
		if (nums.size() == 1) return nums[0];

		int prepre = nums[0];
		int pre = max(nums[0], nums[1]);
		int ans = pre;

		for (int i = 2; i < nums.size(); ++i) {
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

//	vector<int> test = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	vector<int> test = { 2, 3, 2, 4 };
	cout << ans->rob(test) << endl;
	
}