class FoodRatings {
private:
    struct cmp {
        bool operator() (const pair<int, string>& a, const pair<int, string>& b) const {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        }
    };
    
    unordered_map<string, pair<int, string>> foods_; // food -> [rating, cuisine]
    unordered_map<string, set<pair<int, string>, cmp>> m_; // cuisine -> {[rating1, food1], [rating2, food2]}

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            foods_[foods[i]] = {ratings[i], cuisines[i]};
            m_[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [oldRating, type] = foods_[food];
        foods_[food] = {newRating, type};
        m_[type].erase({oldRating, food});
        m_[type].insert({newRating, food});
    }
    
    string highestRated(string cuisine) {
        return (*m_[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
