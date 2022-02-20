# 2160. Minimum Sum of Four Digit Number After Splitting Digits

```cpp
int minimumSum(int num) {
    vector<int> A;
    while (num) {
        A.push_back(num % 10);
        num /= 10;
    }
    sort(A.begin(), A.end());
    return A[0] * 10 + A[2] + A[1] * 10 + A[3];
}
```
