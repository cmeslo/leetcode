class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> lost;
        for (auto& m : matches) {
            if (!lost.count(m[0]))
                lost[m[0]] = 0;
            lost[m[1]]++;
        }
        vector<vector<int>> res(2);
        for (auto& [p, cnt] : lost) {
            if (cnt == 0)
                res[0].push_back(p);
            if (cnt == 1)
                res[1].push_back(p);
        }
        return res;
    }
};
