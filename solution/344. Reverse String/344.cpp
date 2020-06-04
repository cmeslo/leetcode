class Solution {
public:
    void reverseString(vector<char>& s) {
        // 方法一
        int i = 0, j = s.size()-1;
        while (i < j) {
            swap(s[i++], s[j--]);
        }
        
        // 方法二
        //reverse(s.begin(), s.end());
    }
};
