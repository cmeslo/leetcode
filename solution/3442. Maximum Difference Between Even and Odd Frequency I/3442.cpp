class Solution {
public:
    int maxDifference(string s) {
        vector<int> f(26);
        for (char& c : s)
            ++f[c - 'a'];
        
        int max_odd = 0, min_even = s.size();
        for (int i = 0; i < 26; ++i) {
            if (f[i]) {
                if (f[i] % 2)
                    max_odd = max(max_odd, f[i]);
                else
                    min_even = min(min_even, f[i]);
            }
        }
        return max_odd - min_even;
    }
};
