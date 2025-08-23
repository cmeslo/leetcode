class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> m;
        
        for (int x : bills) {
            if (x == 5) {
                m[x]++;
            } else if (x == 10) {
                if (m[5]-- < 0)
                    return false;
                m[10]++;
            } else if (x == 20) {
                if (m[10] > 0 && m[5] > 0) {
                    m[10]--;
                    m[5]--;
                } else if (m[5] >= 3) {
                    m[5] -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
