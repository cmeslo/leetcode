class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 0, r = INT_MAX, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (count(bloomDay, k, mid) >= m)
                r = mid;
            else
                l = mid + 1;
        }
        return l == INT_MAX ? -1 : l;
    }
    
    int count(vector<int>& bloomDay, int k, int t) {
        int res = 0, cnt = 0;
        for (int x : bloomDay) {
            if (x <= t) {
                if (++cnt == k) {
                    cnt = 0;
                    res++;
                }
            } else {
                cnt = 0;
            }
        }
        return res;
    }
};
