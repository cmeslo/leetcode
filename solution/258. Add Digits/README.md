# 258. Add Digits

## Solution 1: Simulation

```cpp
int addDigits(int num) {
    while (num >= 10) {
        int temp = 0;
        while (num) {
            temp += num % 10;
            num /= 10;
        }
        num = temp;
    }
    return num;
}
```

## Solution 2: math

```cpp
int addDigits(int num) {
    if (num == 0) return 0;
    if (num % 9 == 0) return 9;
    return num % 9;
}
```
