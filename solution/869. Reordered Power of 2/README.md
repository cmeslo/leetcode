# 869. Reordered Power of 2

## Solution 1 - 把數字"正規化"

把所有 2 的次方數，"正規化"並保存到 set 裡，

再把 N "正規化"，看看是否能在 set 裡找到。

```cpp
bool reorderedPowerOf2(int N) {
    static unordered_set<string> powerOfTwo;
    if (powerOfTwo.empty()) {
        for (int i = 0; i < 32; ++i) {
            string str = to_string(1 << i);
            sort(begin(str), end(str));
            powerOfTwo.insert(str);
        }
    }

    string str = to_string(N);
    sort(begin(str), end(str));
    return powerOfTwo.count(str);
}
```
