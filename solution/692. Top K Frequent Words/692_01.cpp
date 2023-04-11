class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (string& w : words)
            ++m[w];
        
        vector<pair<int, string>> A;
        for (auto [word, cnt] : m)
            A.push_back({cnt, word});
        sort(A.begin(), A.end(), [](auto& a, auto& b) {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        });
        vector<string> res;
        for (int i = 0; i < k; ++i)
            res.push_back(A[i].second);
        return res;
    }
};
