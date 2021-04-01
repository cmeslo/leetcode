# 1663. Smallest String With A Given Numeric Value

## 解釋

要找 lexicographically smallest string，

就代表前面要越小越好，相應地、後面要越大越好，例如：

```
k = 30
a a a a z ---- ✔，這個更好
a a a b y ---- ✘
```

## Solution: Reverse，從後往前、構造字符串

```cpp
class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        
        while (k >= 26 && k - 26 > n - 1) {
            ans += 'z';
            --n;
            k -= 26;
        }
        
        ans += nth_letter(k - n + 1);
        
        while (--n)
            ans += 'a';
        
        reverse(begin(ans), end(ans));
        return ans;
    }
    
private:
    char nth_letter(int n) {
        return " abcdefghijklmnopqrstuvwxyz"[n];
    }
};
```

更優雅的寫法：

```cpp
string getSmallestString(int n, int k) {
    string ans(n, 'a');

    k -= n;
    while (k > 0) {
        int tmp = min(25, k);
        ans[--n] += tmp;
        k -= tmp;
    }
    return ans;
}
```
