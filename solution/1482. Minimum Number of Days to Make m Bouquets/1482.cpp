class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 0, r = INT_MAX, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (checkOK(bloomDay, m, k, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l == INT_MAX ? -1 : l;
    }
    
    bool checkOK(vector<int>& bloomDay, int m, int k, int t) {
        int cnt = 0;
        for (int x : bloomDay) {
            if (x <= t) {
                if (++cnt == k) {
                    cnt = 0;
                    if (--m == 0)
                        return true;
                }
            } else {
                cnt = 0;
            }
        }
        return false;
    }
};
