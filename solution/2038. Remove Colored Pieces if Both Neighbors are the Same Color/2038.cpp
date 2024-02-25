class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        
        int cntA = 0, cntB = 0;
        int A = 0, B = 0;
        colors.push_back('#');
        
        for (int i = 0; i <= n; ++i) {
            if (i && colors[i-1] != colors[i]) {
                if (colors[i-1] == 'A')
                    cntA += max(0, A - 2);
                else
                    cntB += max(0, B - 2);
            }
            if (colors[i] == 'A') {
                B = 0;
                ++A;
            } else if (colors[i] == 'B') {
                A = 0;
                ++B;
            }
        }
        // cout << cntA << ", " << cntB << endl;
        return cntA > cntB;
    }
};

// ABBBBBBBAAA
