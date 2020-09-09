class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        int h1 = -1, h2 = -1, m1 = -1, m2 = -1;
        int max_mins = -1;
        for (int a = 0; a < 4; ++a) {
            if (A[a] > 2) continue;
            for (int b = 0; b < 4; ++b) {
                if (b == a) continue;
                if (A[a] == 2 && A[b] > 3) continue;
                for (int c = 0; c < 4; ++c) {
                    if (c == a || c == b) continue;
                    if (A[c] > 5) continue;
                    
                    int d = 6 - a - b - c;
                    int mins = (A[a]*10 + A[b]) * 60 + (A[c]*10 + A[d]);
                    if (max_mins < mins) {
                        max_mins = mins;
                        h1 = A[a], h2 = A[b], m1 = A[c], m2 = A[d];
                    }
                }
            }
        }
        
        if (h1 == -1 || h2 == -1 || m1 == -1 || m2 == -1) return "";
        return to_string(h1) + to_string(h2) + ':' + to_string(m1) + to_string(m2);
    }
};
