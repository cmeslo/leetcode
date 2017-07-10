#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		if (matrix.empty()) return false;
		if (!target) return false;

		vector<int> firstCol, &firstRow = matrix.front();;

		for (auto i = matrix.begin(); i != matrix.end(); ++i) {
			if ((*i).empty()) return false;
			firstCol.push_back((*i).front());
		}

		int x = firstRow.size(), y = firstCol.size();

		for (auto i = firstRow.begin(); i != firstRow.end(); ++i) {
			if ((*i) > target) {
				x = i - firstRow.begin();
				break;
			}
			else if ((*i) == target) {
				return true;
			}
		}
		for (auto i = firstCol.begin(); i != firstCol.end(); ++i) {
			if ((*i) > target) {
				y = i - firstCol.begin();
				break;
			}
			else if ((*i) == target) {
				return true;
			}
		}

		for (auto i = matrix.begin(); i != matrix.begin() + y; ++i) {
			vector<int> &currentRow = *i;
			for (auto j = currentRow.begin(); j != currentRow.begin() + x; ++j) {
				if (target == *j) return true;
			}
		}

		return false;
	}
};

void main()
{
	auto ans = new Solution;

// 	vector<vector<int>> test = {
// 		{ 1, 4, 7, 11, 15 },
// 		{ 2, 5, 8, 12, 19 },
// 		{ 3, 6, 9, 16, 22 },
// 		{ 10, 13, 14, 17, 24 },
// 		{ 18, 21, 23, 26, 30 }
// 	};

	vector<vector<int>> test = {
		{ 1, 2, 3, 4, 5 },
		{ 6, 7, 8, 9, 10 },
		{ 11, 12, 13, 14, 15 },
		{ 16, 17, 18, 19, 20 },
		{ 21, 22, 23, 24, 25 }
	};


	cout << ans->searchMatrix(test, 25) << endl;
	
}