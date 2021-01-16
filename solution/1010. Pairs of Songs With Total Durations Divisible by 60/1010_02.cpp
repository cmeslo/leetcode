class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> remainders(60);
        int ans = 0;
        
        for (int t : time) {
            ans += remainders[(600 - t) % 60];
            ++remainders[t % 60];
        }
        
        return ans;
    }
};
