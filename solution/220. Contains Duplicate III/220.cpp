#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if (nums.size() < 2) return false;

		set<long long> window;

		for (int i = 0; i < nums.size(); ++i) {
			if (i > k) window.erase(nums[i - k - 1]);
			// | x - nums[i] | <= t
			// -t <= x - nums[i] <= t  -----------> x >= nums[i] - t, x - nums[i] <= t

			// x >= nums[i] - t
			auto it = window.lower_bound((long long)nums[i] - (long long)t);
			// x - nums[i] <= t
			if (it != window.end() && (long long)*it - (long long)nums[i] <= t) return true;
			window.insert(nums[i]);
		}
		return false;
	}
};

void main()
{
	auto ans = new Solution;

	//vector<int> test = {0}; //k=0, t=0, expect=false
	//vector<int> test = { 1, 2 }; //k=0, t=0, expect=false
	//vector<int> test = { -1, -1 }; //k=1, t=0;
	//vector<int> test = {2, 2}; //k=3, t=0;
	//vector<int> test = {1}; //k=1, t=1;
	//vector<int> test = {-3, 3}; //k=2, t=4;
	//vector<int> test = {-1, 2147483647}; //k=1, t=2147483647, expect=false
	//vector<int> test = { 2147483647, -2147483647 }; //k=1, t=2147483647, expetc=false
	vector<int> test = { -2147483647, -2147483647 }; //k=3, t=3, expect=true

	cout << ans->containsNearbyAlmostDuplicate(test, 3, 3) << endl;
}