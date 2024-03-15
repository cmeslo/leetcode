class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            return __builtin_popcount(a) < __builtin_popcount(b)
                || (__builtin_popcount(a) == __builtin_popcount(b) && a < b);
        });
        return arr;
    }
};
