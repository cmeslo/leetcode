# 848. Shifting Letters

## Example:

```py
Input: s = "abc", shifts = [3,5,9]

   a  b  c
+  3 
+  5  5 
+  9  9  9
= 17 14  9
   r  p  l

Output: "rpl"
```

## Code:

```cpp
string shiftingLetters(string s, vector<int>& shifts) {
    int cnt = 0;
    for (int i = shifts.size() - 1; i >= 0; --i) {
        cnt = (cnt + shifts[i]) % 26;
        s[i] = (s[i] - 'a' + cnt) % 26 + 'a';
    }
    return s;
}
```
