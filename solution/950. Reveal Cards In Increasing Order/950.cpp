class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.rbegin(), deck.rend());
        deque<int> q;
        for (int card : deck) {
            if (!q.empty()) {
                int back = q.back(); q.pop_back();
                q.push_front(back);
            }
            q.push_front(card);
        }
        
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop_front();
        }
        return ans;
    }
};


// 2 3 5 7 11 13 17
    

// 17
// 13 17
// 11 17 13
// 7  13 11 17
// 5  17  7 13 11
// 3  11  5 17  7 13
// 2  13  3 11  2  3  5  7
