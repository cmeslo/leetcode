class Solution {
public:
    string intToRoman(int num) {
        static const vector<int> A = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        static const vector<string> S = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string res = "";
        for (int i = 0; i < A.size(); ++i) {
            while (num >= A[i]) {
                res += S[i];
                num -= A[i];
            }
        }
        return res;
    }
};
