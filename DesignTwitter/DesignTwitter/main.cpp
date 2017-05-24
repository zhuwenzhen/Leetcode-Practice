//
//  main.cpp
//  DesignTwitter
//
//  Created by Wenzhen Zhu on 3/24/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Twitter{
    
    /** Initialize your data structure here. */
    struct Tweet{
        int time;
        int id;
        Tweet(int time, int id) : time (time), id (id) {}
    };
    
    unordered_map<int, vector<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> following; // array of users followed by u
    
    int time;
    
public:
    Twitter(): time(0) {}
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId){
        tweets[userId].emplace_back(time++, tweetId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId){
        vector<pair<Tweet *, Tweet *>> h; // pair of pointers (begin, current)
        for(auto& u: following[userId]){
            auto& t = tweets[u];
            if(t.size() > 0){
                h.emplace_back(t.data(), t.data() + t.size() - 1);
            }
        }
        
        auto& t = tweets[userId];
        if(t.size() > 0){
            h.emplace_back(t.data(), t.data() + t.size() - 1);
        }
        
        auto f = [] (const pair<Tweet*, Tweet*>& x, const pair<Tweet*, Tweet*>& y){
            return x.second->time < y.second->time;
        };
        make_heap(h.begin(), h.end(), f);
        
        const int n = 10;
        vector<int> o;
        o.reserve(n);
        
        for(int i = 0; i < n && !h.empty(); i++){
            pop_heap(h.begin(), h.end(), f);
            
            auto& hb = h.back();
            o.push_back(hb.second->id);
            
            if(hb.first == hb.second--){
                h.pop_back();
            } else {
                push_heap(h.begin(), h.end(), f);
            }
        }
        return o;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId){
        if(followerId != followeeId){
            following[followerId].insert(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId){
        following[followerId].erase(followeeId);
    }
};

void printVectorInt(vector<int> nums){
    for (auto elem: nums){
        cout << elem << " ";
    }
    cout << endl;
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

int main(int argc, const char * argv[]) {
    
    Twitter twitter;
    
    twitter.postTweet(1, 5);
    twitter.postTweet(1, 10);
    cout << 1e-4 << endl;
    printVectorInt(twitter.getNewsFeed(1));
    
    return 0;
}
