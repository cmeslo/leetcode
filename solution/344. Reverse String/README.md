# 344. Reverse String

## Solution: Two Pointers

### C++

```cpp
void reverseString(vector<char>& s) {
    // 方法一
    int i = 0, j = s.size()-1;
    while (i < j) {
        swap(s[i++], s[j--]);
    }

    // 方法二
    //reverse(s.begin(), s.end());
}
```

### Java

```java
public void reverseString(char[] s) {
    int i = 0, j = s.length-1;
    char tmp;
    while (i < j) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++; j--;
    }
}
```
