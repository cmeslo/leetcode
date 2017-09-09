#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

// 23 / 23 test cases passed.
// Runtime: 35 ms

class Twitter {

	struct Tweet
	{
		int id;
		int time;
		Tweet(int id, int time) : id(id), time(time) {};
	};
	struct OrderByTime
	{
		bool operator() (const Tweet& a, const Tweet& b) { return a.time < b.time; };
	};

	int time;
	unordered_map<int, vector<Tweet>> tweets;
	unordered_map<int, unordered_set<int>> following;

public:
	/** Initialize your data structure here. */
	Twitter() : time(0) {}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		tweets[userId].emplace_back(tweetId, time++);
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
  
		priority_queue<Tweet, vector<Tweet>, OrderByTime> pq;
		for (auto& u : following[userId]) {
			auto& ts = tweets[u];
			if (ts.size() > 0) {
				for (auto& t : ts) pq.push(t);
			}
		}

		auto& ts = tweets[userId];
		if (ts.size() > 0) {
			for (auto& t : ts) pq.push(t);
		}

		vector<int> news;
		const int n = 10;
		for (int i = 0; i < n && !pq.empty(); ++i) {
			news.push_back(pq.top().id);
			pq.pop();
		}
		return news;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		if (followerId != followeeId)
			following[followerId].insert(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		following[followerId].erase(followeeId);
	}
};

/**
* Your Twitter object will be instantiated and called as such:
* Twitter obj = new Twitter();
* obj.postTweet(userId,tweetId);
* vector<int> param_2 = obj.getNewsFeed(userId);
* obj.follow(followerId,followeeId);
* obj.unfollow(followerId,followeeId);
*/

void main()
{
	Twitter* test = new Twitter;

	test->postTweet(1, 1);
	test->postTweet(1, 2);
	test->postTweet(1, 3);

	test->follow(1, 2);
	test->follow(1, 3);

	test->postTweet(2, 4);
	test->postTweet(2, 5);
	test->postTweet(2, 6);

	test->postTweet(3, 7);
	test->postTweet(3, 8);
	test->postTweet(3, 9);
	test->postTweet(3, 10);

	test->postTweet(2, 11);

	auto news = test->getNewsFeed(1);

	for (int t : news) {
		cout << t << endl;
	}
}
