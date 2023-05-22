class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> m;
        for (int x : tasks) m[x]++;
        
        int ans = 0;
        for (auto [k, v] : m) {
            if (v == 1) return -1;
            ans += v / 3 + (v % 3 ? 1 : 0);
        }
        return ans;
    }
};
