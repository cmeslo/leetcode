# 29. Divide Two Integers

## Solution 1 - 加法、TLE

```cpp
int divide(int dividend, int divisor) {
    if (dividend == 0) return 0;
    long cnt = 0;
    int positive = (dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0) ? true : false;

    int a = abs(dividend);
    long b = 0;

    if (abs(dividend) == abs(divisor))
        return positive ? 1 : -1;

    while (a > b) {
        b += abs(divisor);
        ++cnt;
        if (cnt > INT_MAX) return positive ? INT_MAX : INT_MIN;
    }

    if (a == b)
        return positive ? cnt :  - cnt;
    else
        return positive ? cnt - 1 : - (cnt - 1);
}
```

## Solution 2 - 左移

既然慢慢加法不夠快，那就不斷乘以2，盡量快的去扣掉一大部分數；剩下的一小部分，再重新重複這個步驟扣。

然後最麻煩是 case (-2147483648, 1)，因為它們abs後，商計算出來是2147483648，超出了INT_MAX，所以要特別處理。

而 case (-2147483648, -1) 不會有問題，因為它的商本來就超出了INT_MAX，要取INT_MAX。

```cpp
int divide(int dividend, int divisor) {
    long quotient  = 0;
    // if (dividend < 0) sign *= -1;
    // if (divisor < 0) sign *= -1;
    int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

    int a = abs(dividend);
    long b = abs(divisor);

    while (a >= b) {
        long c = b;
        long count = 1;
        while ((c << 1) <= a) { // 如果 c 乘以2後仍然小於 a，就讓她乘
            c <<= 1;
            count <<= 1;
        }
        quotient += count;
        a -= c;
    }

    if (quotient * sign > INT_MAX) // quotient * sign 是針對case (-2147483648, 1)，原本是 quotient > INT_MAX
        return INT_MAX;
    else
        return quotient * sign;
}
```
