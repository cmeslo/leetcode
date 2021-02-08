class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int n = S.size();
        long cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (isdigit(S[i])) {
                int times = S[i] - '0';
                if (cnt * times < K) {
                    cnt *= times;
                } else if (K % cnt == 0) { // last character in cnt
                    return decodeAtIndex(S.substr(0, i), cnt);
                } else {
                    return decodeAtIndex(S.substr(0, i), K % cnt);
                }
            } else {
                ++cnt;
                if (K == cnt || K == 0)
                    return string(1, S[i]);
            }
        }
        return "";
    }
};
