class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int, int> freq, sum;
        freq[0] = 1;
        int res = 0, x = 0;
        for (int i = 0; i < arr.size(); ++i) {
            x ^= arr[i];
            res += freq[x] * i - sum[x];
            freq[x]++;
            sum[x] += i + 1;
        }
        return res;
    }
};


// . . a [. b . c . i] . .
    
// xor[0:a] xor[0:b] xor[0:c] xor[0:i]

// (b - a - 1)
// (c - a - 1) + (c - b - 1)
// (i - a - 1) + (i - b - 1) + (i - c - 1)

// res += freq[x] * i - sum[x]
// freq[x]++;
// sum[x] += i - 1
