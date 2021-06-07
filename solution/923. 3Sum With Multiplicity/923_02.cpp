class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        vector<long> m(101);
        for (int x : arr) ++m[x];
        
        long ans = 0;
        for (int a = 0; a <= target / 3; ++a) {
            for (int b = a; b <= target / 2; ++b) {
                int c = target - a - b;
                if (0 <= c && c <= 100 && b <= c) {
                    if (!m[a] || !m[b] || !m[c]) continue;
                    if (a == b && b == c)
                        ans += m[a] * (m[a] - 1) * (m[a] - 2) / 6;
                    else if (a == b && b != c)
                        ans += m[a] * (m[a] - 1) / 2 * m[c];
                    else if (a != b && b == c)
                        ans += m[a] * m[b] * (m[b] - 1) / 2;
                    else if (a < b && b < c)
                        ans += m[a] * m[b] * m[c];
                }
            }
        }
        return ans % 1000000007;
    }
};
