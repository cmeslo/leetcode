# 1249. Minimum Remove to Make Valid Parentheses

## Solution: stack

```cpp
string minRemoveToMakeValid(string s) {
    stack<int> lefts;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(')
            lefts.push(i);
        else if (s[i] == ')') {
            if (!lefts.empty())
                lefts.pop();
            else
                s[i] = '*'; // 無法匹配的右括號，標記為 *
        }
    }

    while (!lefts.empty()) {
        s[lefts.top()] = '*'; // 無法匹配的左括號，標記為 *
        lefts.pop();
    }

    string ans;
    for (char& c : s)
        if (c != '*')
            ans += c;

    return ans;
}
```
