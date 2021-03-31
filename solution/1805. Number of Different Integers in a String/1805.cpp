class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> s;
        
        int i = 0;
        while (i < word.size()) {
            if (isdigit(word[i])) {
                string str = "";
                while (isdigit(word[i]) && word[i] == '0')
                    ++i;
                while (isdigit(word[i]))
                    str += word[i++];
                s.insert(str);
            } else {
                ++i;
            }
        }
        return s.size();
    }
};
