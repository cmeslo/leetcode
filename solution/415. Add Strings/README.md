# 415. Add Strings

## Solution: Two pointers

### C++

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

### Java

```java
public String addStrings(String num1, String num2) {
    int i = num1.length() - 1, j = num2.length() - 1;
    int carry = 0;
    StringBuilder sb = new StringBuilder();
    while (i >= 0 || j >= 0 || carry > 0) {
        int a = i >= 0 ? num1.charAt(i--) - '0' : 0;
        int b = j >= 0 ? num2.charAt(j--) - '0' : 0;
        int sum = a + b + carry;
        sb.append(sum % 10);
        carry = sum / 10;
    }
    String res = sb.reverse().toString();
    return res;
}
```
