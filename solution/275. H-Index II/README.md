# 275. H-Index II

## 275_01.cpp
時間複雜度 ```O(N)```

## 275_02.cpp
時間複雜度 ```O(logN)```

二分查找的最佳方案：

```cpp
while (l < r) {
    mid = l + (r-l)/2;
    if (A[mid] < target)
        l = mid + 1;
    else
        r = mid
}
return l;
```

解釋如下:

https://www.zhihu.com/question/36132386/answer/530313852
