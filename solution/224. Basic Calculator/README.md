# 224. Basic Calculator

## Solution: stack

```cpp
int calculate(string s) {
    stack<int> st;
    int res = 0;
    int num = 0;
    int sign = 1;
    for (char& c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == '+') {
            res += sign * num;
            num = 0;
            sign = 1;
        } else if (c == '-') {
            res += sign * num;
            num = 0;
            sign = -1;
        } else if (c == '(') {
            st.push(res);
            res = 0;
            st.push(sign);
            sign = 1;
        } else if (c == ')') {
            res += sign * num;
            num = 0;
            res = st.top() * res; st.pop();
            res += st.top(); st.pop();
        }
    }
    res += sign * num;
    return res;
}
```
