//
// Created by aleafall on 17-9-22.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define  A 4+5
#define B A*A

class Twitter {
	unordered_map<int, unordered_set<int>> follows, fans;
	unordered_map<int, vector<pair<int, int>>> tweets;
public:
	/** Initialize your data structure here. */
	Twitter() {

	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		follows[userId].insert(userId);
		tweets[userId].emplace_back(userId, tweetId);
		for (auto &&item :fans[userId]) {
			tweets[item].emplace_back(userId, tweetId);
		}
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		int cnt = 0;
		vector<int> ans;
		for (int i = (int) tweets[userId].size() - 1; i >= 0 && cnt < 10; --i) {
			if (follows[userId].count(tweets[userId][i].first)) {
				ans.push_back(tweets[userId][i].second);
				++cnt;
			}
		}
		return ans;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		if (followerId == followeeId) {
			return;
		}
		fans[followeeId].insert(followerId);
		follows[followerId].insert(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		if (followerId == followeeId) {
			return;
		}
		fans[followeeId].erase(followerId);
		follows[followerId].erase(followeeId);
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

int main() {

	return 0;
}