class Solution {
public:
    int passThePillow(int n, int time) {
        int q = time / (n - 1);
        int r = time % (n - 1);
        if (q % 2) return n - r;
        return 1 + r;
    }
};
