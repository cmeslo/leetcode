class Solution {
public:
    int minOperations(int n) {
        int a1 = n % 2 ? 2 : 1;
        int an = n - 1;
        return (n / 2) * (a1 + an) / 2;
    }
};
