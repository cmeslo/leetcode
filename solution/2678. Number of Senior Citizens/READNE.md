# 2678. Number of Senior Citizens

```cpp
int countSeniors(vector<string>& details) {
    int res = 0;
    for (string& d : details) {
        int age = stoi(d.substr(11, 2));
        if (age > 60)
            ++res;
    }
    return res;
}
```
