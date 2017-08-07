#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ans = 0;
		
		for (int i = 0; i < 32; ++i) {
			int col = 0;
			for (int j = 0; j < nums.size(); ++j) {
				col += (nums[j] >> i) & 1;
			}
			ans |= (col % 3) << i;
		}
		return ans;
	}
};

void main()
{
	auto ans = new Solution;

	vector<int> test = { 1, 1, 1, 2, 3, 3, 3 };

	cout << ans->singleNumber(test) << endl;
}