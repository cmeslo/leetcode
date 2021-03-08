class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(begin(wordList), end(wordList));
        if (!dict.count(endWord)) return 0;
        
        int step = 0;
        int len = beginWord.length();
        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};
        
        while (!q1.empty() && !q2.empty()) {
            if (q1.size() > q2.size()) // 先擴展size較小的queue
                swap(q1, q2);
            
            ++step;
            unordered_set<string> q;
            for (string word : q1) {
                for (int i = 0; i < len; ++i) {
                    char tmp = word[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[i] = c;
                        if (q2.count(word)) return step + 1;
                        if (dict.count(word)) {
                            dict.erase(word);
                            q.insert(word);
                        }
                    }
                    word[i] = tmp;
                }
            }
            swap(q1, q);
        }
        
        return 0;
    }
};
