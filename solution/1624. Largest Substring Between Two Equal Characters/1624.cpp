class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        const int n = s.size();
        int res = -1;
        vector<int> A(26, n);
        for (int i = 0; i < n; ++i) {
            int j = s[i] - 'a';
            res = max(res, i - A[j] - 1);
            A[j] = min(A[j], i);
        }
        return res < 0 ? -1 : res;
    }
};
