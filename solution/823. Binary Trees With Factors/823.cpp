class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        
        sort(begin(arr), end(arr));
        unordered_map<int, long> m;
        
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            ++m[arr[i]];
            for (int j = 0; j < i; ++j) {
                if (arr[i] % arr[j] == 0 && m.count(arr[i] / arr[j])) {
                    m[arr[i]] += m[arr[j]] * m[arr[i] / arr[j]];
                }
            }
            ans += m[arr[i]];
        }

        return ans % 1000000007;
    }
};
