class Solution {
public:
    int numSteps(string s) {
        const int n = s.size();
        int one = count(s.begin(), s.end(), '1');
        int res = 0, carry = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (one == 1 && s[i] == '1')
                break;
            
            int x = s[i] - '0' + carry;
            if (x == 0) {
                res += 1; // divide it by 2
            } else if (x == 1) {
                carry = 1;
                res += 2; // add 1 + divide by 2
            } else if (x == 2) {
                carry = 1;
                res += 1;  // divide it by 2
            }
        }
        return res;
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
