class Solution {
public:
    // example1:
    //   10 + 11 ==> 1 + 20 ==> 21 + 0
    // example2: 
    //   456 + 789 = 1245
    //   sum without carry: 135
    //   sum only carry: 111 ==> 1110
    //   1110 + 135 = 1245

    int getSum(int a, int b) {
        if (b == 0) return a;
        int sum = a ^ b;
        int carry = (a & b) << 1;
        return getSum(sum, carry);
        
        // in 1 line:
        // return b == 0 ? a : getSum(a ^ b, (a & b) << 1);
    }
};
