class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        
        return trim(helper(num));
    }
    
private:
    vector<string> LESS_THAN_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> TENS = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    string helper(int num) {
        if (num >= 1000000000) return (helper(num / 1000000000) + " Billion " + helper(num % 1000000000));
        if (num >= 1000000) return (helper(num / 1000000) + " Million " + helper(num % 1000000));
        if (num >= 1000) return (helper(num / 1000) + " Thousand " + helper(num % 1000));
        if (num >= 100) return trim(helper(num / 100) + " Hundred " + helper((num % 100)));
        if (num >= 20) return trim(TENS[num / 10] + " " + helper(num % 10));
        return LESS_THAN_20[num];
    }
    
    string trim(string s) {
        int i = s.size() - 1;
        while (i >= 0 && s[i] == ' ') {
            s.pop_back();
            i--;
        }
        return s;
    }
};
