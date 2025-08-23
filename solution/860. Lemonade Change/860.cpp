class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int x : bills) {
            if (x == 5)
                five++;
            else if (x == 10)
                five--, ten++;
            else if (x == 20) {
                if (ten > 0)
                    five--, ten--;
                else
                    five -= 3;
            }
            if (five < 0) return false;
        }
        return true;
    }
};
