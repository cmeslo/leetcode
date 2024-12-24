class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        const int n = score.size();
        vector<string> A = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        
        vector<pair<int, int>> rank(n);
        for (int i = 0; i < n; ++i)
            rank[i] = {score[i], i};
        
        sort(rank.rbegin(), rank.rend());
        
        vector<string> res(n);
        for (int i = 0; i < n; ++i) {
            int idx = rank[i].second;
            res[idx] = (i < 3 ? A[i] : to_string(i + 1));
        }
        
        return res;
    }
};
