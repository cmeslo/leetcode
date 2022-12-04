# 32. Longest Valid Parentheses

## Solution 1

把不合法的括號，全部變成 * 號。

```cpp
int longestValidParentheses(string s) {
    int n = s.size();

    stack<int> st; // open parentheses
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(')
            st.push(i);
        else {
            if (st.empty())
                s[i] = '*';
            else
                st.pop();
        }
    }

    while (!st.empty()) {
        s[st.top()] = '*';
        st.pop();
    }

    int ans = 0, cnt = 0;
    for (int i = 0; i <= n; ++i) {
        if (i == n || s[i] == '*') {
            ans = max(ans, cnt);
            cnt = 0;
        } else {
            ++cnt;
        }
    }

    return ans;
}
```

## Solution 2

stack 裡保存對上一個非法括號的 index。

### 寫法一

```cpp
int longestValidParentheses(string s) {
    int n = s.size();
    int ans = 0;

    stack<int> st;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(')
            st.push(i);
        else {
            if (!st.empty() && s[st.top()] == '(') {
                st.pop();
                ans = max(ans, i - (st.empty() ? -1 : st.top()));
            } else {
                st.push(i);
            }
        }
    }

    return ans;
}
```

### 寫法二

stack 裡預先插入-1，處理特殊情況。

```cpp
int longestValidParentheses(string s) {
    int ans = 0;
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(')
            st.push(i);
        else {
            st.pop();
            if (!st.empty())
                ans = max(ans, i - st.top());
            else
                st.push(i);
        }
    }
    return ans;
}
```

### 寫法三

```cpp
int longestValidParentheses(string s) {
    int ans = 0;
    s = '#' + s;
    stack<int> st;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ')' && s[st.top()] == '(') {
            st.pop();
            ans = max(ans, i - st.top());
            continue;
        }
        st.push(i);
    }
    return ans;
}
```
