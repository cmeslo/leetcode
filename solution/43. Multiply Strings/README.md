# 43. Multiply Strings

```cpp
string multiply(string A, string B) {
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    vector<int> ans(A.size() + B.size());
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < B.size(); ++j) {
            int cur = (A[i] - '0') * (B[j] - '0') + ans[i + j];
            ans[i + j] = cur % 10;
            ans[i + j + 1] += cur / 10;
        }
    }

    string res = "";
    int i = ans.size() - 1;
    while (i >= 0 && ans[i] == 0) --i;
    if (i < 0) return "0";

    while (i >= 0)
        res.push_back(ans[i--] + '0');
    return res;
}
```

or

```cpp
string multiply(string num1, string num2) {
    string res;
    int n1 = num1.size(), n2 = num2.size();
    vector<int> pos(n1 + n2, 0);

    for (int i = n1 - 1; i >= 0; --i) {
        for (int j = n2 - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = pos[p2] + mul;

            pos[p1] += sum / 10;
            pos[p2] = sum % 10;
        }
    }

    for (int p : pos)
      if (!(res.empty() && p == 0))
        res.push_back(p + '0');

    return res.empty()? "0" : res;
}
```
