class Solution {
public:
    int minimumPushes(string word) {
        vector<int> f(26);
        for (char& c : word)
            f[c - 'a']++;
        
        sort(f.rbegin(), f.rend());
        
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            res += f[i] * (i / 8 + 1);
        }
        return res;
    }
};


// 3 2 1
