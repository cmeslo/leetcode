class Solution {
public:
    int numberOfSteps (int num) {
        int ans = 0;
        while (num) {
            ans += (num & 1) ? 2 : 1;
            num >>= 1;
        }
        return max(0, ans - 1);
    }
};
