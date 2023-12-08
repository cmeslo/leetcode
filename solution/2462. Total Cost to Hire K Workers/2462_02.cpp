class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        using pii = pair<int, int>;
        const int n = costs.size();
        
        priority_queue<pii, vector<pii>, greater<>> pq;
        int i = -1, j = costs.size();
        while (i + 1 < n && i + 1 < candidates) {
            pq.push({costs[++i], i});
        }
        while (j - 1 > i && j - 1 >= n - candidates) {
            pq.push({costs[--j], j});
        }
        
        long res = 0;
        while (!pq.empty() && k--) {
            auto [cost, idx] = pq.top(); pq.pop();
            res += cost;
            if (i + 1 == j) continue;
            
            if (idx <= i) //left
                pq.emplace(costs[++i], i);
            else
                pq.emplace(costs[--j], j);
        }
        return res;
    }
};
