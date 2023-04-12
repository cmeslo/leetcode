class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        using psi = pair<string, int>;
        
        unordered_map<string, int> m;
        for (string& w : words)
            ++m[w];
        
        auto cmp = [](auto& a, auto& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
        priority_queue<psi, vector<psi>, decltype(cmp)> pq(cmp);
        for (auto it : m) {
            pq.push(it);
            if (pq.size() > k)
                pq.pop();
        }
        
        vector<string> res(k);
        for (int i = k - 1; i >= 0; --i) {
            res[i] = pq.top().first;
            pq.pop();
        }
        return res;
    }
};
