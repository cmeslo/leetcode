class Solution {
public:
    int getLucky(string s, int k) {
        int res = 0;
        for (char& c : s) {
            int a = c - 'a' + 1;
            while (a) {
                res += a % 10;
                a /= 10;
            }
        }
        while (--k) {
            int sum = 0;
            while (res) {
                sum += res % 10;
                res /= 10;
            }
            res = sum;
        }
        return res;
    }
};
