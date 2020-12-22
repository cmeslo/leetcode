# 227. Basic Calculator II

## version 1

ugly code

```cpp
int calculate(string s) {
    int n = s.length();
    stack<int> st_num;
    stack<char> st_op;

    for (int i = 0; i < n; ++i) {
        if (s[i] == ' ') continue;

        if (isdigit(s[i])) {
            int num = 0;
            while (i < n && isdigit(s[i]))
                num = num * 10 + (s[i++] - '0');
            --i;

            if (!st_op.empty()) {
                int tmp;
                if (st_op.top() == '*') {
                    tmp = st_num.top() * num;
                    st_num.pop();
                    st_num.push(tmp);
                    st_op.pop();
                } else if (st_op.top() == '/') {
                    tmp = st_num.top() / num;
                    st_num.pop();
                    st_num.push(tmp);
                    st_op.pop();
                } else {
                    st_num.push(num);
                }
            } else {
                st_num.push(num);
            }
        } else {
            st_op.push(s[i]);
        }
    }

    int ans = 0;
    while (!st_num.empty()) { // 不能直接從數字棧中取兩個數，從操作符棧中取一個符號，比如 "1*2-3/4+5*6-7*8+9/10" 會出錯
        int num = st_num.top(); st_num.pop(); 
        if (st_op.empty()) {
            ans += num;
        } else {
            if (st_op.top() == '+') {
                ans += num;
            } else if (st_op.top() == '-') {
                ans -= num;
            }
            st_op.pop();
        }
    }

    return ans;
}
```

## version 2

clean code

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
                int tmp = op == '*' ? st.top() * num : st.top() / num;
                st.pop();
                st.push(tmp);
            }
            op = s[i];
            num = 0;
        }

    }

    int ans = 0;
    while (!st.empty()) {
        ans += st.top(); st.pop();
    }

    return ans;
}
```
