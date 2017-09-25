# 138. Copy List with Random Pointer

## 138_01.cpp
Accepted with poor runtime.

## 138_02.cpp
A special solution with constant space complexity O(1) and linear time compexity O(N) reference [here](https://discuss.leetcode.com/topic/7594/a-solution-with-constant-space-complexity-o-1-and-linear-time-complexity-o-n) and [here](http://fisherlei.blogspot.com/2013/11/leetcode-copy-list-with-random-pointer.html).

3 steps:
  1. copy and insert each nodes to the original list
  2. copy random
  3. split duplicated nodes as answer
  
  ![138_02.png](https://github.com/cmeslo/leetcode/blob/master/solution/138.%20Copy%20List%20with%20Random%20Pointer/138_02.png?raw=true)
