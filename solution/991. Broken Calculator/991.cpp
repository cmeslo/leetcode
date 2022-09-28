class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0;
        while (startValue < target) {
            if (target % 2)
                target += 1;
            else
                target /= 2;
            ans++;
        }
        return ans + startValue - target;
    }
};



// x2x2x2x2x2[-1-1-1...]
//               k
    
// -1-1-1-1x2x2x2x2
    
//     [-1-1-1...] x2
//         k/2 + 1
