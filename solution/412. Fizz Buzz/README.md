# 412. Fizz Buzz

## Solution 1
```cpp
vector<string> fizzBuzz(int n) {
    vector<string> ans(n);

    for (int i = 1; i <= n; ++i) {
        if (i % 15 == 0) ans[i-1] = "FizzBuzz";
        else if (i % 3 == 0) ans[i-1] = "Fizz";
        else if (i % 5 == 0) ans[i-1] = "Buzz";
        else ans[i-1] = to_string(i);
    }

    return ans;
}
```

## Solution 2
```cpp
vector<string> fizzBuzz(int n) {
    vector<string> ans(n);

    for (int i = 1; i <= n; ++i) {
        string tmp = "";
        if (i % 3 == 0) tmp.append("Fizz");
        if (i % 5 == 0) tmp.append("Buzz");
        if (!tmp.length()) tmp.append(to_string(i));
        ans[i-1] = tmp;
    }

    return ans;
}
```
