# 869. Reordered Power of 2

## Solution 1 - 正規化 - 排序

例如：1021 -> "0112"

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

## Solution 2 - 正規化 - counter

因為 1 <= n <= 10^9，所以最多只會有9個相同的數字，

把 9876543210 每一個數字的出現次數保存起來，例如：1021 -> 0000000120

如果範圍太大的話，可以用 hash 或者 用上面排序的方法。

```cpp
class Solution {
public:
    bool reorderedPowerOf2(int N) {
        long res = counter(N);
        for (int i = 0; i < 32; ++i) {
            if (counter(1 << i) == res)
                return true;
        }
        return false;
    }
    
private:
    long counter(int n) {
        long res = 0;
        for (; n; n /= 10)
            res += pow(10, n % 10);
        return res;
    }
};
```

代碼裡用了 long，因為比如 N = 999999999，用 int 會因為 UndefinedBehavior 而出現 runtime error，

但因為 test case 不嚴格，用 int 也可以AC。

