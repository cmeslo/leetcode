class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        vector<int> s_v(10, 0), g_v(10, 0);
        
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                a++;
            } else {
                s_v[secret[i] - '0']++;
                g_v[guess[i] - '0']++;
            }
        }
        
        for (int i = 0; i < s_v.size(); ++i)
            b += min(s_v[i], g_v[i]);
        
        return to_string(a) + 'A' + to_string(b) + 'B';
    }
};
