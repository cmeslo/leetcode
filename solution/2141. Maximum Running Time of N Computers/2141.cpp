class Solution {
public:
    using ll = long long;
    
    long long maxRunTime(int n, vector<int>& batteries) {
        ll l = 0, r = accumulate(batteries.begin(), batteries.end(), 0L), mid;
        while (l < r) {
            mid = r - (r - l) / 2;
            if (checkOK(n, batteries, mid))
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
    
    // bool checkOK(int n, vector<int>& B, ll time) {
    //     ll sum = 0;
    //     for (ll b : B) {
    //         sum += min(b, time);
    //     }
    //     return sum >= 1L * n * time;
    // }
    
    bool checkOK(int n, vector<int>& B, ll time) {
        ll rubbish = 0;
        for (int b : B) {
            if (b >= time) {
                n--;
            } else {
                rubbish += b; // 把廢的電池聚合起來給一台電腦用 time 分鐘
                if (rubbish >= time) {
                    rubbish -= time;
                    n--;
                }
            }
        }
        return n <= 0;
    }
};


