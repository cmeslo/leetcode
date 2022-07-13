# 227. Basic Calculator II

## Solution 1: Two stack

```cpp
int calculate(string s) {
    stack<int> numStack;
    stack<char> opStack;

    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            opStack.push(s[i]);
        } else if (isdigit(s[i])) {
            int num = 0;
            while (i < n && isdigit(s[i])) {
                num = num * 10 + (s[i++] - '0');
            }
            numStack.push(num);
            i--;

            if (!opStack.empty()) {
                if (opStack.top() == '-') {
                    opStack.pop();
                    opStack.push('+');
                    numStack.top() = - numStack.top();
                } else if (opStack.top() == '*' || opStack.top() == '/') {
                    int b = numStack.top(); numStack.pop();
                    int a = numStack.top(); numStack.pop();
                    numStack.push(opStack.top() == '*' ? a * b : a / b);
                    opStack.pop();
                }
            }
        }
    }

    while (!opStack.empty()) {
        int b = numStack.top(); numStack.pop();
        int a = numStack.top(); numStack.pop();
        numStack.push(a + b);
        opStack.pop();
    }
    return numStack.top();
}
```

## Solution 2: One stack

```cpp
int calculate(string s) {
    int n = s.length();
    stack<int> st;
    char op = '+';
    int num = 0;

    for (int i = 0; i < n; ++i) {
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i == n - 1) {
            if (op == '+') st.push(num);
            else if (op == '-') st.push(-num);
            else if (op == '*' || op == '/') {
                int tmp = st.top(); st.pop();
                st.push(op == '*' ? tmp * num : tmp / num);
            }
            num = 0;
            op = s[i];
        }
    }

    int ans = 0;
    while (!st.empty()) {
        ans += st.top(); st.pop();
    }

    return ans;
}
```
