class Solution {
public:
    string reverseWords(string s) {
        string res;
        istringstream iss(s);
        string word;
        while (iss >> word) {
            int i = 0, j = word.size() - 1;
            while (i < j)
                swap(word[i++], word[j--]);
            res += ' ' + word;
        }
        return res.substr(1);
    }
};
