#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums)
	{
		int sum = nums[0], ans = nums[0];

		for (int i = 1; i < nums.size(); ++i) {
			sum = max(sum + nums[i], nums[i]);
			ans = max(sum, ans);
		}
		return ans;
	}
};

void main()
{
	auto ans = new Solution;

	vector<int> test = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	cout << ans->maxSubArray(test) << endl;
	
}