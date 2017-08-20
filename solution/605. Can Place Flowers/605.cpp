#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int a = -1;
		int length = flowerbed.size();
		for (int i = 0; i < length; ++i) {
			if (flowerbed[i] == 1) {
				if (a == -1) 
					n -= i / 2;
				else
					if (i - a > 3) n -= (i - a) / 3;
				a = i;
			}
			else if (i == length - 1) {
				if (a == -1) {
					if (length % 2 == 0)
						n -= length / 2;
					else
						n -= length / 2 + 1;
				}
				else {
					n -= (i - a) / 2;
				}
			}
		}
		return  n <= 0;
	}
};

void main()
{
	Solution *sol = new Solution;
	//vector<int> test = { 1, 0, 0, 0, 1 }; //n = 1, expect: true
	//vector<int> test = { 1, 0, 0, 0, 1 }; //n = 2, expect: false
	//vector<int> test = { 1, 0, 1, 0, 0, 0, 1 }; //n = 2, expect: false
	//vector<int> test = { 0, 0, 1, 0, 0, 0, 0 }; //n = 3, expect: true
	vector<int> test = { 0, 0, 0, 0, 0, 0, 0, 0}; // n = 4, expect: true

	cout << sol->canPlaceFlowers(test, 1) << endl;
}