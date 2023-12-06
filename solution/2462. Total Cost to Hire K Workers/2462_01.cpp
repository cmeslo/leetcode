class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        using pii = pair<int, int>;
        const int n = costs.size();
        
        priority_queue<int, vector<int>, greater<>> pql, pqr;
        int i = -1, j = costs.size();
        while (i + 1 < n && i + 1 < candidates) {
            pql.push(costs[++i]);
        }
        while (j - 1 > i && j - 1 >= n - candidates) {
            pqr.push(costs[--j]);
        }
        
        long res = 0;
        while ((!pql.empty() || !pqr.empty()) && k--) {
            if (pql.empty()) {
                res += pqr.top(); pqr.pop();
                if (i < j - 1)
                    pqr.push(costs[--j]);
            } else if (pqr.empty()) {
                res += pql.top(); pql.pop();
                if (i + 1 < j)
                    pql.push(costs[++i]);
            } else {
                if (pql.top() <= pqr.top()) {
                    res += pql.top(); pql.pop();
                    if (i + 1 < j)
                        pql.push(costs[++i]);
                } else {
                    res += pqr.top(); pqr.pop();
                    if (i < j - 1)
                        pqr.push(costs[--j]);
                }
            }
        }
        return res;
    }
};
