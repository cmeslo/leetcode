class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char a = 'a', b = 'b';
        if (x < y) { // 保證 'ab', 即 x 是最大的
            swap(a, b);
            swap(x, y);
        }
        string s1 = remove(s, a, b); // 先移除 'ab'
        string s2 = remove(s1, b, a); // 後移除 'ba'

        return (s.size() - s1.size()) / 2 * x + (s1.size() - s2.size()) / 2 * y;
    }
    
private:
    string remove(string& s, char& a, char& b) {
        string st;
        for (char& c : s) {
            if (!st.empty() && st.back() == a && c == b)
                st.pop_back();
            else
                st.push_back(c);
        }
        return st;
    }
};

// ab -> x
// ba -> y
// aba -> get(ba) -> a
//     -> get(ab) -> a
// bab -> get(ab) -> b
//     -> get(ba) -> b

// cdbcbaabab -> ba = 5
// cdbcabab -> ba = 5
// cdbcab -> ab = 4
// cdbc -> ab = 4

// cdbcbaabab -> ba = 5
// cdbcabab -> ba = 5
// cdbcab -> ba = 5
// cdbc -> ab = 4
