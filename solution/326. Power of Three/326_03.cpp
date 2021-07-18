class Solution {
public:
    bool isPowerOfThree(int n) {
        // 找到 int 範圍內的最大的、3的次方數，通過以下代碼可以找到 19，所以是 3^19 
        // int cnt = 0;
        // while (pow(3, cnt) <= INT_MAX)
        //     ++cnt;
        // cout << cnt - 1 << endl;
        
        int mx = 1162261467; // pow(3, 19)
        return n > 0 && mx % n == 0;
    }
};
