class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int n = S.length();
        long cnt = 0, i;
        for (i = 0; i < n && cnt < K; ++i) {
            if (isdigit(S[i]))
                cnt *= (S[i] - '0');
            else
                ++cnt;
        }
        
        while (i--) {
            if (isdigit(S[i])) {
                cnt /= (S[i] - '0');
                K %= cnt;
            } else {
                if (K % cnt-- == 0)
                    return string(1, S[i]);
            }
        }
        
        return "";
    }
};
