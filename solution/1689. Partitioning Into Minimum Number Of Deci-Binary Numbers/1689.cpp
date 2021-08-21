class Solution {
public:
    int minPartitions(string n) {
        char ans = '0';
        
        for (char& c : n) {
            if (c > ans) ans = c;
            if (ans == '9') break;
        }
        
        return ans - '0';
    }
};
