class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(begin(people), end(people));
        
        int boats = 0;
        int l = 0, r = n - 1;
        while (l <= r) {
            if (people[l] + people[r] <= limit)
                ++l;
            --r;
            ++boats;
        }
        return boats;
    }
};
