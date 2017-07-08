#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isPerfectSquare(int num)
	{
		int i = 1;
		while (num > 0) {
			num -= i;
			i += 2;
		}
		return 0 == num;
	}
};

void main()
{
	auto ans = new Solution;
	cout << ans->isPerfectSquare(10) << endl;
	
}