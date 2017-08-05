#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {

		vector<string> ans;
		unordered_map<string, int> m;

		int n = s.length();

		for (int i = 0; i < n - 9; ++i) {
			string cur = s.substr(i, 10);
			m[cur]++;
		}

		for (auto i : m) {
			if (i.second > 1) ans.push_back(i.first);
		}
		return ans;
	}
};

void main()
{
	auto ans = new Solution;

	vector<string> test = ans->findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");

	for (string i : test) {
		cout << i.c_str() << endl;
	}

}