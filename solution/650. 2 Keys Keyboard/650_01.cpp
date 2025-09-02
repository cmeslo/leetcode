class Solution {
public:
    int minSteps(int n) {
        if (n <= 1) return 0;
        for (int x = 2; x < n; ++x) {
            if (n % x == 0)
                return minSteps(n / x) + x;
        }
        return n;
    }
};

// 1: 0
// 2: 2
// 3: 3
// 4: 4
// 5: 

// A <----copy
// AA <---paste
// AA <---copy
// AAAA <-paste

// A <-------copy
// AA <------paste
// AAA <-----paste
// AAAA <----paste
// AAAAA <---paste
