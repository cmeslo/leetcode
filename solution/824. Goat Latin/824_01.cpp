class Solution {
public:
    string toGoatLatin(string S) {
        int n = S.length();
        string ans;
        string ma = "maa";
        
        int i = 0;
        while (i < n) {
            if (S[i] == ' ') {
                while (i < n && S[i] == ' ') i++;
                if (ans.length() != 0 && i < n) ans += ' ';
                continue;
            }
            
            int j = i + 1;
            while (j < n && S[j] != ' ') j++;
            
            string cur;
            if (j - i == 1) {
                cur = S[i];
            } else {
                if (!isVowel(S[i]))
                    cur = S.substr(i + 1, j - i - 1) + S[i];
                else
                    cur = S.substr(i, j - i);
            }
            
            cur += ma;
            ma += 'a';
            
            ans += cur;
            i = j;
        }
        
        return ans;
    }
    
private:
    const string VOWEL = "aeiouAEIOU";
    
    bool isVowel(const char& c) {
        for (const char& vowel : VOWEL)
            if (vowel == c) return true;
        return false;
    }
};
