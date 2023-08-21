class Solution {
public:
    int partitionString(string s) {
        int cnt = 0, res = 1;
        for (char& c : s) {
            int i = c - 'a';
            if ((cnt & (1 << i)) != 0) {
                res++;
                cnt = 0;
            }
            cnt |= (1 << i);
        }
        return res;
    }
};
