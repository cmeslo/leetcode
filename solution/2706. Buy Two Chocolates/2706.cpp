class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mn1 = 101, mn2 = 101;
        for (int x : prices) {
            if (x < mn1) {
                mn2 = mn1;
                mn1 = x;
            } else if (x < mn2) {
                mn2 = x;
            }
        }
        return mn1 + mn2 > money ? money : money - mn1 - mn2;
    }
};
