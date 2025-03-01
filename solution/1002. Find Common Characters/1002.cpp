class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> f(26, INT_MAX);
        for (string& w : words) {
            vector<int> f2(26);
            for (char& c : w)
                f2[c - 'a']++;
            for (int i = 0; i < 26; ++i) {
                f[i] = min(f[i], f2[i]);
            }
        }
        vector<string> res;
        for (int i = 0; i < 26; ++i) {
            while (f[i]--)
                res.push_back(string(1, i + 'a'));
        }
        return res;
    }
};
