class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for (char& x : columnTitle)
            ans = ans * 26 + (x - 'A' + 1);
        return ans;
    }
};


// 1  2  3  ... 26
// A  B  C  ... Z

// 27 28 29 ... 52
// AA AB AC ... AZ

// 53 53 55 ... 78
// BA BB BC ... BZ

// AAA
