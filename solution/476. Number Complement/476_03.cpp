class Solution {
public:
    int findComplement(int num) {
        long i = 1;
        while (i <= num)
            i <<= 1;
        return (i - 1) ^ num;
    }
};

// 0 1 0 1
// 1 0 0 0
// 0 1 1 1
// 1 0 1 0
