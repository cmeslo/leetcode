class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        int pos = 0;
        while (num) {
            res |= ((num ^ 1) & 1) << pos++;
            num >>= 1;
        }
        return res;
    }
};
