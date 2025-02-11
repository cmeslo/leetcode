class Solution {
public:
    int numSteps(string s) {
        int res = 0, carry = 0;
        for (int i = s.size() - 1; i > 0; --i) {
            if (s[i] - '0' + carry == 1) {
                carry = 1;
                res += 1; // add 1
            }
            res += 1; // divide it by 2
        }
        return res + carry; // carry 出現過一次, 就只會不斷向左移而不會消失
    }
};


// . . . . . x
// . . . . . 0
// . . . . . 1

// 0 1 0
// 0 0 1
// -----
// 0 1 1

// 0 1 1
// 0 0 1
// -----
// 1 0 0
