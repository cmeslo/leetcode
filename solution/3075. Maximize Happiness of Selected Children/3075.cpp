class Solution {
public:
    long long maximumHappinessSum(vector<int>& H, int k) {
        sort(H.rbegin(), H.rend());
        long res = 0;
        for (int i = 0, dec = 0; i < k && H[i] > dec; ++i, ++dec) {
            res += H[i] - dec;
        }
        return res;
    }
};
