class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        while (i >= 0 || j >= 0) {
            int m = i >= 0 ? a[i--] - '0' : 0;
            int n = j >= 0 ? b[j--] - '0' : 0;
            int sum = m + n + carry;
            res = to_string(sum % 2) + res;
            carry = sum / 2;
        }
        return carry == 1 ? "1" + res : res;
    }
};
