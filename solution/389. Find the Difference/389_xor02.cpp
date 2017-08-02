class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
		for (int i = 0; i < s.length(); ++i) {
			ans ^= s[i];
			ans ^= t[i];
		}
		ans ^= t[t.length() - 1];
		return ans;
    }
};