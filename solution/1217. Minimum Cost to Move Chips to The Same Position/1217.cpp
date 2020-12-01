class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int count_odd = 0, count_even = 0;
        
        for (int n : position) {
            if (n % 2 == 0)
                ++count_even;
            else
                ++count_odd;
        }
        
        return min(count_even, count_odd);
    }
};
