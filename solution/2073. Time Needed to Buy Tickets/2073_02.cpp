class Solution {
public:
    int timeRequiredToBuy(vector<int>& T, int k) {
        int ans = 0;
        for (int i = 0; i < T.size(); ++i) {
            if (i <= k)
                ans += min(T[k], T[i]);
            else
                ans += min(T[k] - 1, T[i]);
        }
        return ans;
    }
};
