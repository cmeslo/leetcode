#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		if (matrix.empty() || matrix[0].size() == 0) return false;

		int row = 0;
		int col = matrix[0].size() - 1;

		while (row <= matrix.size() - 1 && col >= 0)
		{
			if (target == matrix[row][col]) {
				return true;
			}
			else if (target < matrix[row][col]) {
				col--;
			}
			else if (target > matrix[row][col]) {
				row++;
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

// 	vector<vector<int>> test = {
// 		{ 1, 2, 3, 4, 5 },
// 		{ 6, 7, 8, 9, 10 },
// 		{ 11, 12, 13, 14, 15 },
// 		{ 16, 17, 18, 19, 20 },
// 		{ 21, 22, 23, 24, 25 }
// 	};

	vector<vector<int>> test = {
		{ -5 }
	};


	cout << ans->searchMatrix(test, -5) << endl;
	
}