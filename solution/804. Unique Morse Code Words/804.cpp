class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        static vector<string> morse_code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        
        for (const string& word : words) {
            string code = "";
            for (const char& letter : word)
                code += morse_code[letter - 'a'];
            s.insert(code);
        }
        
        return s.size();
    }
};
