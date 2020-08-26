class Solution {
public:
    string toGoatLatin(string S) {
        istringstream iss(S);
        string ans, word;
        
        int cnt = 1;
        while (iss >> word) {
            ans += (vowel.count(word[0]) ? word : word.substr(1) + word[0]);
            ans += "ma" + string(cnt++, 'a') + ' ';
        }
        
        ans.pop_back();
        return ans;
    }

private:
    const unordered_set<char> vowel {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
};
