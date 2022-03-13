class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<int> B(n);
        for (int i = 0; i < n; ++i) {
            int b = 0;
            for (char& c : arr[i]) {
                if ((b >> (c - 'a')) & 1) {
                    b = INT_MAX;
                    break;
                }
                b |= (1 << (c - 'a'));
            }
            B[i] = b;
        }
        
        int ans = 0;
        for (int state = 0; state < (1 << n); ++state) {
            int cur = 0;
            for (int i = 0; i < 26; ++i) {
                if ((state >> i) & 1) {
                    if (cur & B[i]) {
                        cur = 0;
                        break;
                    }
                    cur |= B[i];
                }
            }
            if (cur != INT_MAX)
                ans = max(ans, __builtin_popcount(cur));
        }
        return ans;
    }
};
