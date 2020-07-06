class Solution {
public:
    int nthUglyNumber(int n) {
        static vector<int> uglys{1};
        static int i2 = 0, i3 = 0, i5 = 0;
        while (uglys.size() < n) {
            const int next2 = uglys[i2]*2;
            const int next3 = uglys[i3]*3;
            const int next5 = uglys[i5]*5;
            const int next = min(next2, min(next3, next5));
            uglys.push_back(next);
            if (next == next2) i2++;
            if (next == next3) i3++;
            if (next == next5) i5++;
        }
        return uglys[n-1];
    }
};
