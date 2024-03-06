class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = people.size();

        unordered_map<int, int> m;
        for (auto& f : flowers) {
            m[f[0]]++;
            m[f[1] + 1]--;
        }
        vector<pair<int, int>> diff(m.begin(), m.end());
        sort(diff.begin(), diff.end());

        vector<pair<int, int>> P;
        for (int i = 0; i < n; ++i)
            P.push_back({people[i], i});
        sort(P.begin(), P.end());

        vector<int> res(n);

        int j = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            while (j < diff.size() && diff[j].first <= P[i].first) {
                sum += diff[j].second;
                j++;
            }
            res[P[i].second] = sum;
        }
        return res;
    }
};
