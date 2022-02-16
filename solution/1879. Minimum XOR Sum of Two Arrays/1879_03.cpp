class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        using PII = pair<int, int>;
        int n = nums1.size();
        
        priority_queue<PII, vector<PII>, greater<>> pq; // {cost, state}
        pq.push({0, 0});
        vector<bool> visited(1 << n, false);
        
        while (!pq.empty()) {
            auto [cost, state] = pq.top(); pq.pop();
            if (visited[state]) continue;
            visited[state] = true;
            
            int j = __builtin_popcount(state);
            if (j == n) return cost;
            
            for (int i = 0; i < n; ++i) {
                if ((state >> i) & 1) continue;
                int nextState = state + (1 << i);
                if (visited[nextState]) continue;
                int nextCost = cost + (nums1[i] ^ nums2[j]);
                pq.push({nextCost, nextState});
            }
        }
        return -1;
    }
};
