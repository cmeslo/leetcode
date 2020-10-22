class Solution {
public:
    int bitwiseComplement(int N) {
        if (N < 2) return 1 - N;
        
        int num = 2;
        while (num < N)
            num *= 2;
        
        return num == N ? (num - 1) : (num - 1 - N);
    }
};
