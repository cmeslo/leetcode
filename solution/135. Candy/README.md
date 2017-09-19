# 135. Candy

## 135_01.cpp
Straightforward, add candy with rating from low to high. Accepted but got poor runtime.

example:

1, 5, 3, 4, 7, 2

1, 1, 1, 1, 1, 1  
1, 1, 1, 1, 1 ,1 <== 2  
1, 1, 1, 1, 1 ,1 <== 3  
1, 1, 1, 2, 1 ,1 <== 4  
1, 2, 1, 2, 1 ,1 <== 5  
1, 2, 1, 2, 3 ,1 <== 7  


## 135_02.cpp

We travse 2 times, left-to-right and right-to-left.

example:

1, 5, 3, 4, 7, 2

1, 2, 1, 2, 3, 1 <== left-to-right  
1, 2, 1, 1, 2, 1 <== right-to-left  
