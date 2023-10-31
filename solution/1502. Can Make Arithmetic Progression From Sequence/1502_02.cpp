class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        const int n = arr.size();
        const auto [loit, hiit] = minmax_element(begin(arr), end(arr));
        const auto [lo, hi] = pair{*loit, *hiit};
        if ((hi - lo) % (n - 1)) return false;
        const int diff =  (hi - lo) / (n - 1);
        if (diff == 0) return true;
        for (int i = 0; i < n; ++i) {
            if ((arr[i] - lo) % diff) return false;
            const int idx = (arr[i] - lo) / diff;
            if (idx == i) continue;
            if (idx < i || arr[idx] == arr[i]) return false;
            swap(arr[i--], arr[idx]);
        }
        return true;
    }
};
