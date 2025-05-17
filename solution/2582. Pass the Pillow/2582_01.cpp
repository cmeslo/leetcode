class Solution {
public:
    int passThePillow(int n, int time) {
        int dir = 0; // 0: right, 1: left
        int i = 1;
        for (int t = 0; t < time; ++t) {
            if (dir == 0) {
                if (++i == n)
                    dir = !dir;
            } else {
                if (--i == 1)
                    dir = !dir;
            }
        }
        return i;
    }
};
