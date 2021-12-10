class Solution {
public:
    int trap(vector<int>& H) {
        int n = H.size();
        vector<int> left(n), right(n);
        for (int i = 1; i < n - 1; ++i) {
            left[i] = max(H[i - 1], left[i - 1]);
            right[n - i - 1] = max(H[n - i], right[n - i]);
        }
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int h = min(left[i], right[i]) - H[i];
            if (h > 0)
                res += h;
        }
        return res;
    }
};
