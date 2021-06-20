# 1903. Largest Odd Number in String

找到最右邊第一個 odd number。

```cpp
string largestOddNumber(string num) {
    for (int i = num.size() - 1; i >= 0; --i) {
        if ((num[i] - '0') % 2)
            return num.substr(0, i + 1);
    }
    return "";
}
```
