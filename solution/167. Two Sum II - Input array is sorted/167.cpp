#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target)
	{
		vector<int> ans;
		vector<int>::iterator left, right;
		left = numbers.begin();
		right = numbers.end() - 1;

		while (*left + *right != target) {
			if (*left + *right < target) {
				left++;
			}
			else {
				right--;
			}
		}
		ans.push_back(left - numbers.begin() + 1);
		ans.push_back(right - numbers.begin() + 1);
		return ans;
	}
};

void main()
{
	auto ans = new Solution;
	//vector<int> numbers = { 2, 7, 11, 15 };
	vector<int> numbers = { 2, 3, 4 };

	vector<int> indexs = ans->twoSum(numbers, 6);

	cout << indexs.at(0) << ", " << indexs.at(1) << endl;
	
}