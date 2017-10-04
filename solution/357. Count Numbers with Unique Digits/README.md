# 357. Count Numbers with Unique Digits #

## 357.cpp

using a dynamic programming approach, hints:
1. ```Let f(k) = count of numbers with unique digits with length equals k.```
2. ```f(1) = 10, ..., f(k) = 9 * 9 * 8 * ... (9 - k + 2)```
