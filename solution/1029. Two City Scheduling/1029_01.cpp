// time complexity: O(NlogN)
// Runtime: 4 ms
// beats 98.97 % of cpp submissions.

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](const auto& c1, const auto& c2) {
            return c1[0] - c1[1] < c2[0] - c2[1];
        });
        
        int ans = 0, n = costs.size();
        for (int i = 0; i < n; i++) {
            ans += (i < n/2) ? costs[i][0] : costs[i][1];
        }
        return ans;
    }
};
