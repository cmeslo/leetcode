# 415. Add Strings

```cpp
string addStrings(string num1, string num2) {
    string res = "";
    int i = num1.size() - 1, j = num2.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int a = i >= 0 ? num1[i--] - '0' : 0;
        int b = j >= 0 ? num2[j--] - '0' : 0;
        int sum = a + b + carry;
        res += sum % 10 + '0';
        carry = sum / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}
```
