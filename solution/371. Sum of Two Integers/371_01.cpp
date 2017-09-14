class Solution {
public:
    int getSum(int a, int b) {
        int index = 1, carry = 0, c = 0;
        
        for (int i = 0; i < sizeof(int) * 8; ++i) {
            c |= (a & index) ^ (b & index) ^ carry;
            carry = (index & ((a & b) | (a & carry) | (b & carry)));
            carry <<= 1;
            index <<= 1;
        }
		return c;
    }
};
