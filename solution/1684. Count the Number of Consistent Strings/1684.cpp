class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> f(26);
        for (char& c : allowed)
            f[c - 'a'] = 1;
        
        int res = 0;
        for (string& w : words) {
            bool ok = true;
            for (char& c : w) {
                if (f[c - 'a'] == 0) {
                    ok = false;
                    break;
                }
            }
            res += ok;
        }
        return res;
    }
};
