class Solution {
public:
    string addStrings(string num1, string num2) {
        int s1 = num1.size() - 1, s2 = num2.size() - 1;
        string res = "";
        int carry = 0;
        
        while (s1 >= 0 || s2 >= 0) {
            int n1 = s1 >= 0 ? num1[s1--] - '0' : 0;
            int n2 = s2 >= 0 ? num2[s2--] - '0' : 0;
            int sum = n1 + n2 + carry;
            res.insert(res.begin(), sum % 10 + '0');
            carry = sum / 10;
        }
        return carry ? "1" + res : res;
    }
};
