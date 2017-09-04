class Solution {
public:
    int longestPalindrome(string s) {
        int res = 0;
		unordered_map<char, int> m;

		for (int i = 0; i < s.size(); ++i) m[s[i]]++;

		bool middle = false;
		for (auto i : m) {
			while (i.second > 1) {
				res += 2;
				i.second -= 2;
			}
			if (i.second == 1 && !middle) {
				res += 1;
				middle = true;
			}
		}
		return res;
    }
};