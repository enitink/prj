#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef struct _Tweet {
    int tweetId;
    int userId;
    int time;
}Tweet;

class CompareTweet {
public:
    bool operator()(const Tweet& t1, const Tweet& t2) {
        return t1.time < t2.time;
    }
};

class Twitter {
    map<int, priority_queue<Tweet, vector<Tweet>, CompareTweet> > userTweetFeeds;
    map<int, vector<int> > usertweets;

public:
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        
    }
    
    vector<int> getNewsFeed(int userId) {
        
    }
    
    void follow(int followerId, int followeeId) {
        
    }
    
    void unfollow(int followerId, int followeeId) {
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */