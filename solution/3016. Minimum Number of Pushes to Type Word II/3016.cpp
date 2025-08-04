class Solution {
public:
    int minimumPushes(string word) {
        vector<int> f(26);
        for (char& c : word)
            f[c - 'a']++;
        
        vector<pair<int, int>> A(26); // freq, key
        for (int i = 0; i < 26; ++i)
            A[i] = {f[i], i};
        
        sort(A.rbegin(), A.rend());
        
        unordered_map<char, int> m;
        for (int i = 0; i < 26; ++i) {
            char c = A[i].second + 'a';
            if (m.count(c)) continue;
            m[c] = i / 8 + 1;
        }
        
        int res = 0;
        for (char& c : word)
            res += m[c];
        return res;
    }
};
