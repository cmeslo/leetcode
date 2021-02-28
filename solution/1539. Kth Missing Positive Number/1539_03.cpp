class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> s(begin(arr), end(arr));
        for (int x = 1; x <= arr.back(); ++x) {
            if (!s.count(x))
                --k;
            if (k == 0)
                return x;
        }
        return arr.back() + k;
    }
};
