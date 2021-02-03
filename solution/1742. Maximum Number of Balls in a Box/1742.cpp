class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> boxes(46);
        int ans = 0;
        for (int x = lowLimit; x <= highLimit; ++x) {
            int sum = 0, num = x;
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            ans = max(ans, ++boxes[sum]);
        }
        return ans;
    }
};
