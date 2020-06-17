# 468. Validate IP Address

```java
for (String token : IP.split("\\.", -1))
```
注意Java的split, 特殊字符要用 ```\\```，例如 ```.``` ```|``` ```$```

limit 用負數，應對 "1.0.1." 的情況

```java
public String[] split(String regex, int limit)
```

If the limit n is greater than zero then the pattern will be applied at most n - 1 times, the array's length will be no greater than n, and the array's last entry will contain all input beyond the last matched delimiter. If n is non-positive then the pattern will be applied as many times as possible and the array can have any length. If n is zero then the pattern will be applied as many times as possible, the array can have any length, and ```trailing empty strings will be discarded.```

split 的使用可以參考 https://docs.oracle.com/javase/7/docs/api/java/lang/String.html#split(java.lang.String,%20int)
