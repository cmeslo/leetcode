# 137. Single Number II

如果是成對出現，可以用 xor 解決，但因為題目是3個一組出現，所以要想出3消的辦法，

只細想，xor 其實就是沒有進位的按位加法，

同樣道埋、不管進位，只要同一列出現了3個1就可以消去，使用對 % 3的方法：

比如 [2,2,3,2]
```
0 1 0
0 1 0
1 0 1
0 1 0
----- 按位相加後
1 3 1
```

```
1 % 3 = 1
3 % 3 = 0
1 % 3 = 1
```
正正就是我們想要的答案 101

要注意一個地方，因為想只做單一列的相加，

所以相加前、把當前列（位）移到最右、再 ```& 1``` 做 mask，加完之後再<strong>移回</strong>相應的位置、並用```|```操作加上

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        
        for (int i = 0; i < 32; i++) {
            int sum = 0;
            for (int n : nums)
                sum += (n >> i) & 1;
            ans |= (sum % 3) << i;
        }
        return ans;
    }
};

```
