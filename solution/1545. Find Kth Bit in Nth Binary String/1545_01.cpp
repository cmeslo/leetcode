class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        
        while (n--)
            s = s + "1" + reverse(invert(s));
        
        return s[k - 1];
    }
    
private:
    string invert(string s) {
        for (char& c : s)
            c = c == '1' ? '0' : '1';
        return s;
    }
    
    string reverse(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            swap(s[l++], s[r--]);
        }
        return s;
    }
};
