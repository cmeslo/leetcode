class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < groupSizes.size(); ++i) {
            m[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> res;
        for (auto& [size, arr] : m) {
            int cnt = arr.size() / size;
            int i = 0;
            while (cnt--) {
                vector<int> cur;
                while (cur.size() < size) {
                    cur.push_back(arr[i++]);
                }
                res.push_back(cur);
            }
        }

        return res;
    }
};
