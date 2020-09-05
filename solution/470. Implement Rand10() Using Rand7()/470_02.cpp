// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int a = 7, b = 7;
        
        while (a == 7)
            a = rand7();
        a %= 2;
        
        while (b > 5)
            b = rand7();
        
        return 5 * a + b;
    }
};
