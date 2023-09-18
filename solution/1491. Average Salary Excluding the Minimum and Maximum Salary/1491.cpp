class Solution {
public:
    double average(vector<int>& salary) {
        int mx = INT_MIN, mn = INT_MAX;
        double sum = 0;
        for (int x : salary) {
            mx = max(mx, x);
            mn = min(mn, x);
            sum += x;
        }
        return (sum - mx - mn) / (salary.size() - 2);
    }
};
