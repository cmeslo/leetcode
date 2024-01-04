class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int res = 0;
        unordered_map<int, int> m;
        for (int x : arr) {
            if (m.count(x - difference))
                m[x] = m[x - difference] + 1;
            else
                m[x] = 1;
            res = max(res, m[x]);
        }
        return res;
    }
};
