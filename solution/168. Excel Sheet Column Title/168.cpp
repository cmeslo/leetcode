class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while (columnNumber) {
            columnNumber--;
            res += (columnNumber % 26) + 'A';
            columnNumber /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


// A ... Z
// 0 ... 25
// 1 ... 26

// AA: A * 26 + A
