class Solution {
public:
    int bitwiseComplement(int n) {
        int x = 1;
        while (x < n)
            x = (x << 1) | 1;
        
        return x ^ n;
    }
};


// 0 0 0 1 0 1 <-- n

// 0 0 0 1 1 1 <-- xor this

// 0 0 0 0 1 0
