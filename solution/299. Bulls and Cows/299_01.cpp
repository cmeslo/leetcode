class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int A = 0, B = 0;
        unordered_map<char, int> m;
        
        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) {
                ++A;
                secret[i] = '#';
            }
            else ++m[guess[i]];
        }
        
        for (int i = 0; i < n; ++i) {
            if (secret[i] == '#') continue;
            if (m.find(secret[i]) != m.end()) {
                ++B;
                --m[secret[i]];
                if (m[secret[i]] == 0) m.erase(secret[i]);
            }
        }
        
        return to_string(A) + 'A' + to_string(B) + 'B';
    }
};
