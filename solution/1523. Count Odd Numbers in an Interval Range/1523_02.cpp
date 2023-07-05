class Solution {
public:
    int countOdds(int low, int high) {
        return (high + 1) / 2 - low / 2;
    }
};

// 1 2 3 -> (3+1)/2 = 2
// 1 2 3 4 -> (4+1)/2 = 2
