class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double l = 0, r = 1, m;
        while (l < r) {
            m = l + (r - l) / 2;
            int cnt = countSmallerOrEqual(arr, m);
            if (cnt < k)
                l = m;
            else if (cnt > k)
                r = m;
            else
                break;
        }
        
        vector<int> res = {-1, -1};
        double ans = 0;
        for (int i = 0; i < arr.size(); ++i) {
            auto pos = lower_bound(arr.begin(), arr.end(), arr[i] * 1.0 / m);
            int j = pos - arr.begin();
            if (pos != arr.end() && arr[i] * 1.0 / arr[j] > ans) {
                ans = arr[i] * 1.0 / arr[j];
                res = {arr[i], arr[j]};
            }
        }
        return res;
    }
    
    int countSmallerOrEqual(vector<int>& arr, double x) {
        int cnt = 0;
        for (int i = 0; i < arr.size(); ++i) {
            auto pos = lower_bound(arr.begin(), arr.end(), arr[i] * 1.0 / x);
            cnt += arr.end() - pos;
        }
        return cnt;
    }
};
