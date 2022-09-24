class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26);
        for (char& c : s)
            count[c - 'a']++;
        
        vector<bool> exists(26, false);
        string ans;
        for (char& c : s) {
            count[c - 'a']--;
            if (exists[c - 'a']) continue;
            while (!ans.empty() && ans.back() > c && count[ans.back() - 'a'] >= 1) {
                exists[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            exists[c - 'a'] = true;
            ans.push_back(c);
        }
        return ans;
    }
};


// cbacdcbc
// ^------------- push c
// ans = c

// cbacdcbc
//  ^------------ c > b, 並且之後還有 c 可以用, 可以 pop 掉 c, push b
// ans = b

// cbacdcbc
//   ^----------- b > a, 並且之後還有 b 可以用, 可以 pop 掉 b, push a
// ans = a

// cbacdcbc
//    ^---------- a < c, 繼續 push c
// ans = ac

// cbacdcbc
//     ^--------- c < d, 繼續 push d
// ans = acd

// cbacdcbc
//      ^-------- d < c, 但後面已經沒有 d 了, 不能 pop, 而且前面已經有 c 了, 不 push 進去
// ans = acd

// cbacdcbc
//       ^-------- d > b, 但後面已經沒有 d 了, 不能 pop, push b
// ans = acdb

// cbacdcbc
//        ^------- b < c, 但前面已經有 c 了, 不 push 進去
// ans = acdb
