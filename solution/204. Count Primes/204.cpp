class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        vector<bool> isPrimes(n, true);
        for (int x = 2; x < n; ++x) {
            if (isPrimes[x]) {
                ++ans;
                for (int i = 2; i * x < n; ++i)
                    isPrimes[i * x] = false;
            }
        }
        return ans;
    }
};
