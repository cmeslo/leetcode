class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};

// n = 6

// 1 2 3 4 5 6
// o o o o o o
// o x o x o x
// o x x x o o
// o x x o o o
// o x x o x o
// o x x o x x

// f(0) = 0
// f(1) = 1
// f(2) = 1
// f(3) = 1
// f(4) = 2
// f(6) = 2
// f(7) = 2
// f(8) = 2
// f(9) = 3
// f(10) = 3
// f(11) = 3
// f(12) = 3
// f(13) = 3
// f(14) = 3
// f(15) = 3

// o o o o
// o x o x
// o x x x
// o x x o
