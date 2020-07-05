class Solution {
public:
    int nthUglyNumber(int n) {
        static vector<int> ugly_nums;
        if (ugly_nums.empty()) {
            for (long a = 1; a < INT_MAX; a*=2)
                for (long b = a; b < INT_MAX; b*=3)
                    for (long c = b; c < INT_MAX; c*=5)
                        ugly_nums.push_back(c);
            sort(ugly_nums.begin(), ugly_nums.end());
        }
        return ugly_nums[n-1];
    }
};
