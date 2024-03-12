class Solution {
public:
    int kthGrammar(int n, int k) {
        int flip = 0;
        while (n > 1) {
            int count = 1 << (n - 1);
            if (k > count / 2) {
                k -= (count / 2);
                flip++;
            }
            n--;
        }
        return flip % 2;
    }
};


// 0
// 0 1
// 01 10
// 0110 1001
// 01101001 10010110

// 0
// 01
// 0110
// 01101001
// 0110100110010110

// 0
// ??
// x?xx
// x?xx x?xx

// nth row = 2^(n - 1) elements
