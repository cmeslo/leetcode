class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> A = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        
        auto cmp = [score](int i, int j) {
            return score[i] < score[j];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        
        const int n = score.size();
        for (int i = 0; i < n; ++i)
            pq.push(i);
        
        int i = 0;
        vector<string> res(n);
        while (!pq.empty()) {
            int idx = pq.top(); pq.pop();
            res[idx] = i < 3 ? A[i] : to_string(i + 1);
            ++i;
        }
        return res;
    }
};
