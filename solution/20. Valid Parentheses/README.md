# 20. Valid Parentheses

## Solution: Stack

### C++

```cpp
bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        } else {
            if (st.empty()) return false;
            if (s[i] == ')' && st.top() != '(') return false;
            if (s[i] == ']' && st.top() != '[') return false;
            if (s[i] == '}' && st.top() != '{') return false;
            st.pop();
        }
    }
    return st.empty();
}
```

### Java

```java
public boolean isValid(String s) {
    Stack<Character> st = new Stack<Character>();
    for (char c : s.toCharArray()) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.isEmpty()) return false;
            if (c == ')' && st.peek() != '(') return false;
            if (c == ']' && st.peek() != '[') return false;
            if (c == '}' && st.peek() != '{') return false;
            st.pop();
        }
    }
    return st.isEmpty();
}
```
