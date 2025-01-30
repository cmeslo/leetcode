class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        const int n = words.size();
        vector<int> L(26);
        for (char& c : letters) ++L[c - 'a'];
        
        int res = 0;
        for (int state = 0; state < (1<<n); ++state) {
            auto f = L;
            int stateOK = true;
            int sum = 0;
            for (int i = 0; i < n && stateOK; ++i) {
                if ((state >> i) & 1) {
                    bool ok = true;
                    for (char& c : words[i]) {
                        if (--f[c - 'a'] < 0) {
                            ok = false;
                            break;
                        }
                        sum += score[c - 'a'];
                    }
                    if (!ok) stateOK = false;
                }
            }
            if (stateOK)
                res = max(res, sum);
        }
        return res;
    }
};
