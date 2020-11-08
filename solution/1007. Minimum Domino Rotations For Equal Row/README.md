# 1007. Minimum Domino Rotations For Equal Row

## 1007_01.cpp
最初實現的寫法，不太簡潔，但原理和 runtime 與下面的方法差不多

```cpp
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        if (A.empty() || B.empty()) return -1;
        return min(helper(A, B), helper(B, A));
    }
    
private:
    int helper(vector<int>& A, vector<int>& B) {
        int a = 0, b = 1; // a is count of fixed A[0], b is count of fixed A[0] after swap(A[0], B[0])
        for (int i = 1; i < A.size(); ++i) {
            if ((A[0] != A[i] && B[0] != A[i]) && (A[0] != B[i] && B[0] != B[i]))
                return -1;

            if (a != INT_MAX && A[0] != A[i])
                a = A[0] == B[i] ? a + 1 : INT_MAX;

            if (b != INT_MAX && B[0] != A[i])
                b = B[0] == B[i] ? b + 1 : INT_MAX;
        }
        
        int ans = min(a, b);
        return ans == INT_MAX ? -1 : ans;
    }
};
```

## 1007_02.cpp

更簡潔的寫法

第一個 for 循環，目標是把所有數字變為 A[0]

第二個 for 循環，目標是把所有數字變為 B[0]

a 和 b，分別代表把數字向上換和向下換的代價

```cpp
int minDominoRotations(vector<int>& A, vector<int>& B) {
    int n = A.size();
    for (int i = 0, a = 0, b = 0; i < n && (A[i] == A[0] || B[i] == A[0]); ++i) {
        if (A[i] != A[0]) ++a;
        if (B[i] != A[0]) ++b;
        if (i == n - 1) return min(a, b);
    }
    for (int i = 0, a = 0, b = 0; i < n && (A[i] == B[0] || B[i] == B[0]); ++i) {
        if (A[i] != B[0]) ++a;
        if (B[i] != B[0]) ++b;
        if (i == n - 1) return min(a, b);
    }
    return -1;
}
```

## 1007_03.cpp

看了別人的解法，很巧妙，

分別記錄兩個數組裡，1 至 6 的出現次數

最後看數字 1 至 6 中，哪一個數字可以在兩行裡分別加起來後（共同出現的會多加了一次，把它減掉）等於 n

那就代表該數字符合要求，可以湊滿一行

```cpp
int minDominoRotations(vector<int>& A, vector<int>& B) {
    int n = A.size();

    vector<int> countA(7, 0), countB(7, 0), same(7, 0);
    for (int i = 0; i < n; ++i) {
        ++countA[A[i]];
        ++countB[B[i]];
        if (A[i] == B[i])
            ++same[A[i]];
    }

    for (int i = 1; i < 7; ++i)
        if (countA[i] + countB[i] - same[i] == n) // 共同出現的會多加了一次，把它減掉
            return n - max(countA[i], countB[i]); // 看看要填補多少個空缺，即交換多少次

    return -1;
}
```
