class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [&](auto& a, auto& b) {
            return a[1] < b[1];
        });

        int res = 1;
        int i = 0;
        for (int j = 1; j < pairs.size(); ++j) {
            if (pairs[j][0] <= pairs[i][1]) continue;
            i = j;
            ++res;
        }
        return res;
    }
};
