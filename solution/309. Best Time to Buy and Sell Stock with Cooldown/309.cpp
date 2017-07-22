#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		
		int n = prices.size();

		if (n < 1) return 0;

		vector<int> s0(n), s1(n), s2(n);

		s0[0] = 0;
		s1[0] = -prices[0];
		s2[0] = INT_MIN;

		for (int i = 1; i < n; ++i) {
			s0[i] = max(s0[i - 1], s2[i - 1]);
			s1[i] = max(s0[i - 1] - prices[i], s1[i - 1]);
			s2[i] = s1[i - 1] + prices[i];
		}

		return max(s0[n - 1], s2[n - 1]);
	}
};

void main()
{
	auto ans = new Solution;

	vector<int> test = { 1, 2, 3, 0, 2 };

	cout << ans->maxProfit(test) << endl;
}