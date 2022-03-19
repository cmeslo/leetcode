# 2180. Count Integers With Even Digit Sum

```cpp
int countEven(int num) {
    int res = 0;
    int x = 2;
    while (x <= num) {
        int sum = 0;
        int temp = x;
        while (temp) {
            sum += temp % 10;
            temp /= 10;
        }
        if (sum % 2 == 0)
            ++res;
        ++x;
    }
    return res;
}
```
