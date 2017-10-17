# 116. Populating Next Right Pointers in Each Node #

## [116_01.cpp](https://github.com/cmeslo/leetcode/blob/master/solution/116.%20Populating%20Next%20Right%20Pointers%20in%20Each%20Node/116_01.cpp) ##
Use queue with level count by perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

## [116_02.cpp](https://github.com/cmeslo/leetcode/blob/master/solution/116.%20Populating%20Next%20Right%20Pointers%20in%20Each%20Node/116_02.cpp) ##
Use queue with level count by size.

## [116_03.cpp](https://github.com/cmeslo/leetcode/blob/master/solution/116.%20Populating%20Next%20Right%20Pointers%20in%20Each%20Node/116_03.cpp) ##
recursion.

## [116_04.cpp](https://github.com/cmeslo/leetcode/blob/master/solution/116.%20Populating%20Next%20Right%20Pointers%20in%20Each%20Node/116_04.cpp) ##
Use ```start``` pointer to record first node of each layer, ```cur``` pointer to traverse each layer. O(1) space.
