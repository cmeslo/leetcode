# 859. Buddy Strings

```cpp
bool buddyStrings(string A, string B) {
    if (A.length() != B.length()) return false;
    
    if (A == B) {
        vector<int> letters(26, 0);  // for case: "aa" "aa"
        for (const char& c : A) {
            if (letters[c - 'a']) return true;
            else ++letters[c - 'a'];
        }
        return false;
    }
    
    int diff1 = -1, diff2 = -1;
    for (int i = 0; i < A.length(); ++i) {
        if (A[i] != B[i]) {
            if (diff1 == -1)
                diff1 = i;
            else if (diff2 == -1) {
                diff2 = i;
                break;
            }
        }
    }
    
    swap(A[diff1], A[diff2]);
    
    return A == B;
}
```
