class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int, vector<int>> m;
        m[0].push_back(-1);
        int res = 0;
        for (int i = 0, prefix = 0; i < arr.size(); ++i) {
            prefix ^= arr[i];
            for (int idx : m[prefix]) {
                res += i - idx - 1;
            }
            m[prefix].push_back(i);
        }
        return res;
    }
};
