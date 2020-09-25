//separate by odd and even

class Solution {
public:
    int rob(vector<int> &num) {
        int a = 0, b = 0;
        for (int i = 0; i < num.size(); ++i) {
            if (i % 2 == 0) {
                a += num[i];
                a = max(a, b);
            } else {
                b += num[i];
                b = max(a, b);
            }
        }
        return max(a, b);
    }
};
