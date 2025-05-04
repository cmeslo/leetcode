class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int odds = 0;
        for (int x : arr) {
            odds = x % 2 ? odds + 1 : 0;
            if (odds == 3)
                return true;
        }
        return false;
    }
};
