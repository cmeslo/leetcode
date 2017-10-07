public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int cur = (n >>> i) & 1;
            cur <<= (31 - i); //there is no unsigned left shift operator <<< in java
            res = res | cur;
        }
        return res;
    }
}
