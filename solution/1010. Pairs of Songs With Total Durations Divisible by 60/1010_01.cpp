// 36 ms, Your runtime beats 99.47 % of cpp submissions.

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        unordered_map<int, int> m;
        for (int t : time) {
            int remainder = t % 60;
            if (m.count((60 - remainder) % 60))
                ans += m[(60 - remainder) % 60];
            ++m[remainder];
        }
        return ans;
    }
};
