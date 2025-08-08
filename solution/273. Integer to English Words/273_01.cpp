class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        
        string res = "";
        int i = 0;
        
        while (num > 0) {
            if (num % 1000 != 0)
                res = helper(num % 1000) + THOUSANDS[i] + " " + res;
            num /= 1000;
            i++;
        }
        
        i = res.size() - 1;
        while (i >= 0 && res[i] == ' ') {
            res.pop_back();
            i--;
        }
        return res;
    }
    
private:
    vector<string> LESS_THAN_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> TENS = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> THOUSANDS = {"", "Thousand", "Million", "Billion"};
    
    string helper(int x) {
        if (x == 0)
            return "";
        if (x < 20)
            return LESS_THAN_20[x] + " ";
        if (x < 100)
            return TENS[x / 10] + " " + helper(x % 10);
        return LESS_THAN_20[x / 100] + " Hundred " + helper(x % 100);
    }
};
