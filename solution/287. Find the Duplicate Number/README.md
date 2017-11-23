# 287. Find the Duplicate Number

## 287_01.cpp
Binary search, considering:

n + 1 = 11
```
1, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10
```

left = 1, mid = 5, right = 10

## 287_02.cpp
Floyd cycle detection algorithm, take a look in [142. Linked List Cycle II](https://github.com/cmeslo/leetcode/tree/master/solution/142.%20Linked%20List%20Cycle%20II)
