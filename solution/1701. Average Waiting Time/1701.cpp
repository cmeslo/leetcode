class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long sum = 0, t = 0;
        for (auto& c : customers) {
            t = max(t, 1L * c[0]) + c[1];
            sum += t - c[0];
        }
        return 1.0 * sum / customers.size();
    }
};
