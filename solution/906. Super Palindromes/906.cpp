class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        long long a = stoll(left);
        long long b = stoll(right);
        
        int ans = 0;
        for (int i = 1; i <= 1e5; ++i) {
            for (int type = 0; type <= 1; ++type) {
                long long palin = getPalindrome(i, type);
                if (palin > 1e9) continue;
                
                long long superPalin = palin * palin;
                if (a <= superPalin && superPalin <= b && isPalindrome(superPalin))
                    ++ans;
            }
        }
        return ans;
    }
    
private:
    long long getPalindrome(int x, int type) {
        long long y = x;
        if (type == 1) x /= 10;
        while (x) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return y;
    }
    
    bool isPalindrome(long long x) {
        string num = to_string(x);
        int i = 0, j = num.length() - 1;
        while (i < j) {
            if (num[i++] != num[j--])
                return false;
        }
        return true;
    }
};
