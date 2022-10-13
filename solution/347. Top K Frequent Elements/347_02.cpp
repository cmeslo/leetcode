class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int x : nums) {
            m[x]++;
        }
        
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<>> pq;
        for (auto [x, count] : m) {
            pq.push({count, x});
            if (pq.size() > k)
                pq.pop();
        }
        
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
