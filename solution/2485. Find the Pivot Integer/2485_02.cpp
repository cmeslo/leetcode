class Solution {
public:
    int pivotInteger(int n) {
        int presum = 0;
        int total = n * (1 + n) / 2;
        for (int x = 1; x <= n; ++x) {
            presum += x;
            if (presum == total - presum + x)
                return x;
        }
        return -1;
    }
};


// [. . . . . {x] . . .}

