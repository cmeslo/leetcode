class Solution {
public:
    bool reorderedPowerOf2(int N) {
        int res = counter(N);
        for (int i = 0; i < 32; ++i) {
            if (counter(1 << i) == res)
                return true;
        }
        return false;
    }
    
private:
    int counter(int n) {
        int res = 0;
        for (; n; n /= 10)
            res += pow(10, n % 10);
        return res;
    }
};
