class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string map = "0123456789abcdef";
        string result = "";
        
        while (num != 0) {
            result = map[num & 15] + result;
            num = (unsigned int) num >> 4;
        }
        return result;
    }
};
