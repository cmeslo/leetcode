#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
        
		vector<int> ans;

		vector<int>::iterator left, right;
		left = nums.begin();
		right = nums.end() - 1;

		for (auto i = nums.begin(); i != nums.end(); ++i) {
			for (auto j = i + 1; j != nums.end(); ++j) {
				if (*i + *j == target) {
					left = i;
					right = j;
					break;
				}
			}
		}
		ans.push_back(left - nums.begin());
		ans.push_back(right - nums.begin());
		return ans;
    }
};

void main()
{
	auto ans = new Solution;
	//vector<int> numbers = { 2, 7, 11, 15 };
	vector<int> numbers = { -1, -2, -3, -4, -5 };

	vector<int> indexs = ans->twoSum(numbers, -8);

	cout << indexs.at(0) << ", " << indexs.at(1) << endl;
	
}