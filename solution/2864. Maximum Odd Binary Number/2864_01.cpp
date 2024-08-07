class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = count(s.begin(), s.end(), '1');
        int n = s.size();
        return string(ones - 1, '1') + string(n - ones, '0') + "1";
    }
};
