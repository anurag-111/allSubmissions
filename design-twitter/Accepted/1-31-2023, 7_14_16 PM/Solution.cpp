// https://leetcode.com/problems/design-twitter

class Twitter {
private: 
    //pairs : [user, tweet]
    vector<pair<int, int>> posts;

    //hash map: {user -> people they follow}
    unordered_map<int, unordered_set<int>> followMap;

public:
    //Twitter() Initializes your twitter object.
    Twitter() {
        
    }
    
    //Composes a new tweet with ID tweetId by the user userId.
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId, tweetId});
    }
    
    //Retrieves the 10 most recent tweet IDs in the user's news feed.
    vector<int> getNewsFeed(int userId) {
        //10 tweets
        int count = 10;
        vector<int> result;

        //since postTweet pushes to the back, for recent we must loop from back
        for (int i = posts.size() - 1; i >= 0; i--) {
            if (count == 0) {
                break;
            }

            int followingId = posts[i].first;
            int tweetId = posts[i].second;
            unordered_set<int> following = followMap[userId];
            
            // add to result if they are following them or if it's a tweet from themselves
            if (following.find(followingId) != following.end() || followingId == userId) {
                result.push_back(tweetId);
                count--;
            }        
        }
        return result;
    }
    
    //The user with ID followerId started following the user with ID followeeId.
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    //The user with ID followerId started unfollowing the user with ID followeeId.
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
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