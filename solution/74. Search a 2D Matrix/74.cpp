#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		if (matrix.empty()) return false;

		vector<int> firstVals;

		for (vector<vector<int>>::iterator i = matrix.begin(); i != matrix.end(); ++i)
		{
			if (!(*i).empty()) {
				firstVals.push_back((*i).front());
			}
		}

		if (firstVals.empty()) return false;

		vector<int>::iterator it = firstVals.begin();
		while (it != firstVals.end() - 1 && *it < target) {
			if (*(it + 1) > target) break;
			it++;
		}

		int col = it - firstVals.begin();
		
		vector<int> row = *(matrix.begin() + col);

		for (auto i = row.begin(); i != row.end(); ++i) {
			if (*i == target) return true;
		}
		return false;
	}
};

void main()
{
	auto ans = new Solution;
	vector<int> z;
// 	vector<int> a = { 1, 3, 5, 7 };
// 	vector<int> b = { 10, 11, 16, 20 };
// 	vector<int> c = { 23, 30, 34, 50 };

	vector<vector<int>> matrixs;
// 	matrixs.push_back(a);
// 	matrixs.push_back(b);
// 	matrixs.push_back(c);
	matrixs.push_back(z);

	cout << ans->searchMatrix(matrixs, 3) << endl;
	
}