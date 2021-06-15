class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(10);
        for (char c : s) {
            if (c == 'z') ++count[0];
            if (c == 'w') ++count[2];
            if (c == 'u') ++count[4];
            if (c == 'x') ++count[6];
            if (c == 'g') ++count[8];
            if (c == 'o') ++count[1]; // 1 - 0 - 2 - 4
            if (c == 't') ++count[3]; // 3 - 2 - 8
            if (c == 'f') ++count[5]; // 5 - 4
            if (c == 's') ++count[7]; // 7 - 6
            if (c == 'i') ++count[9]; // 9 - 8 - 6 - 5
        }
        
        count[1] = count[1] - count[0] - count[2] - count[4];
        count[3] = count[3] - count[2] - count[8];
        count[5] = count[5] - count[4];
        count[7] = count[7] - count[6];
        count[9] = count[9] - count[8] - count[6] - count[5];
        
        string ans;
        for (int i = 0; i < 10; ++i)
            ans += string(count[i], '0' + i);
        return ans;
    }
};
