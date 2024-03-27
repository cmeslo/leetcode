class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        const int n = arr.size();
        vector<int> A { arr[n/4], arr[n/2], arr[n*3/4] }; // 斬開4份, 只有這3個數有可能是答案
        for (int x : A) {
            auto l = lower_bound(arr.begin(), arr.end(), x);
            auto r = upper_bound(arr.begin(), arr.end(), x);
            if (distance(l, r) > n/4)
                return x;
        }
        return -1;
    }
};
