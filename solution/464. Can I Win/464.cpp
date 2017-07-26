#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		if (maxChoosableInteger >= desiredTotal) return true;
		if (maxChoosableInteger * (1 + maxChoosableInteger) / 2 < desiredTotal) return false;
		unordered_map<int, bool> m;
		return canIWin(maxChoosableInteger, desiredTotal, 0, m);
	}

	bool canIWin(int maxChoosableInteger, int total, int visited, unordered_map<int, bool>& m) {
		if (m.find(visited) != m.end()) return m[visited];

		for (int i = 1; i <= maxChoosableInteger; ++i) {
			int mask = 1 << i;
			if ((mask & visited) == 0) { // i not visited
				if (i >= total || !canIWin(maxChoosableInteger, total - i, mask | visited, m)) {
					m[visited] = true;
					return true;
				}
			}
		}
		m[visited] = false;
		return false;
	}
};

void main()
{
	auto ans = new Solution;

	cout << ans->canIWin(10, 11) << endl;
}