class Solution {
public:
    int countOdds(int low, int high) {
        int len = high - low + 1;
        if (len % 2 == 0 || low % 2 == 0) return len / 2;
        return (len + 1) / 2;
    }
};


// 1 2 3 --> 3 / 2 = 2
// 2 3 4 --> 3 / 2 = 1
    
// 1 2 3 4 --> 4 / 2 = 2
// 2 3 4 5 --> 4 / 2 = 2

// 1 2 3 4 5 --> 3
// 2 3 4 5 6 --> 2
