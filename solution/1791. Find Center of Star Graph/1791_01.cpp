class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> m;
        for (int i = 0; i < 2; ++i) {
            m[edges[i][0]]++;
            m[edges[i][1]]++;
        }
        for (auto& [node, cnt] : m)
            if (cnt > 1)
                return node;
        return -1;
    }
};
