class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char ans = keysPressed[0];
        int mx = releaseTimes[0];
        for (int i = 1; i < keysPressed.size(); ++i) {
            int t = releaseTimes[i] - releaseTimes[i - 1];
            if (mx < t) {
                ans = keysPressed[i];
                mx = t;
            } else if (mx == t && ans < keysPressed[i]) {
                ans = keysPressed[i];
            }
        }
        return ans;
    }
};
