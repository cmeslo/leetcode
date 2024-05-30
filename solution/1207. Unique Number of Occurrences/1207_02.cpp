class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int m[2001] = {};
        for (int x : arr) ++m[x + 1000];
        sort(begin(m), end(m));
        for (int i = 1; i < 2001; ++i)
            if (m[i] && m[i - 1] == m[i])
                return false;
        return true;
    }
};
