class Solution {
public:
    int countOrders(int n) {
        const int M = 1e9 + 7;
        long ans = 1;
        for (int i = n; i > 1; --i) {
            ans = ans * i * (2 * i - 1) % M;
        }
        return ans;
    }
};

// n = 2

// p1 p2 d1 d2

// x x x dx

// C(2,1) * C(3,1) = 6  最後一個位放 Delivery，然後前面找一個位放 Pickup
// C(1,1) * C(1,1) = 1  
// ans = 6 * 1 = 6

// C(n, 1) * C(2*n-1, 1)
// C(n-1, 1) * C(2*(n-1)-1, 1)
// ...

// while (n--)
//     ans *= C(n, 1) * C(2*n-1, 1)


