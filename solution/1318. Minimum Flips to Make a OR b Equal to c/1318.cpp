class Solution {
public:
    int minFlips(int A, int B, int C) {
        int res = 0, a = 0, b = 0, c = 0;
        for (int i = 0; i < 32; ++i) {
            a = (A >> i) & 1;
            b = (B >> i) & 1;
            c = (C >> i) & 1;
            if ((a | b) == c) continue;
            
            if (c == 0)
                res += a + b;
            else
                res += 1;
        }
        return res;
    }
};
