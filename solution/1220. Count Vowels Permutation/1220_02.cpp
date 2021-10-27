class Solution {
public:
    int countVowelPermutation(int n) {
        const int M = 1e9 + 7;
        long a = 1, e = 1, i = 1, o = 1, u = 1;
        
        for (int k = 2; k <= n; ++k) {
            long aa = (e + i + u) % M;
            long ee = (a + i) % M;
            long ii = (e + o) % M;
            long oo = i;
            long uu = (i + o) % M;
            a = aa;
            e = ee;
            i = ii;
            o = oo;
            u = uu;
        }
        
        return (a + e + i + o + u) % M;
    }
};
