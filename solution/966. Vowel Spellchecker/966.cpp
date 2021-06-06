class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> dict(begin(wordlist), end(wordlist));
        unordered_map<string, string> cap;
        unordered_map<string, string> vowel;
        
        for (string& word : wordlist) {
            cap.insert({tolow(word), word});
            vowel.insert({todev(word), word});
        }
        
        for (string& query : queries) {
            if (dict.count(query)) continue;
            string lower = tolow(query), devowel = todev(query);
            if (cap.count(lower))
                query = cap[lower];
            else if (vowel.count(devowel))
                query = vowel[devowel];
            else
                query = "";
        }
        
        return queries;
    }
    
private:
    string tolow(string word) {
        for (char& c : word)
            c = tolower(c);
        return word;
    }
    
    string todev(string word) {
        word = tolow(word);
        for (char& c : word)
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                c = '#';
        return word;
    }
};
