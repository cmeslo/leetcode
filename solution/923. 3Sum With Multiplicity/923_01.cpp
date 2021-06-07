class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int mod = 1e9 + 7;
        int n = arr.size();
        int ans = 0;
        unordered_map<int, int> m;
        
        for (int i = 1; i < n; ++i) {
            if (m.count(target - arr[i]))
                ans = (ans + m[target - arr[i]]) % mod;
            
            for (int j = i - 1; j >= 0; --j)
                ++m[arr[i] + arr[j]];
        }
        
        return ans;
    }
};
