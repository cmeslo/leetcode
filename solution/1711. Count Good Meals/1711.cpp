class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        const int k = 1e9 + 7;
        auto& D = deliciousness;
        int n = D.size();
        unordered_map<int, int> m;
        
        int ans = 0;
        for (int d : D) {
            for (int j = 0; j < 22; ++j) {
                int pow = 1 << j;
                if (m.count(pow - d)) {
                    ans += m[pow - d];
                    ans %= k;
                }
            }
            ++m[d];
        }
        
        return ans;
    }
};
