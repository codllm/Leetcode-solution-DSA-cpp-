class Twitter {
public:

    int timmer;

    unordered_map<int,vector<pair<int,int>>> userMap;
    unordered_map<int,set<int>> followMap;

    Twitter() {
        timmer = 0;
    }
    

    void postTweet(int userId, int tweetId) {

        userMap[userId].push_back({timmer,tweetId});
        timmer++;
    }
    

    vector<int> getNewsFeed(int userId) {

        priority_queue<pair<int,int>> pq;


        // own tweets
        for(auto ownPost : userMap[userId])
        {
            pq.push(ownPost);
        }


        // followee tweets
        for(auto followee : followMap[userId])
        {
            for(auto post : userMap[followee])
            {
                pq.push(post);
            }
        }


        vector<int> newsFeed;


        while(!pq.empty() && newsFeed.size()<10)
        {
            newsFeed.push_back(pq.top().second);
            pq.pop();
        }
        return newsFeed;
    }
    

    void follow(int followerId, int followeeId) {

        if(followerId == followeeId) return;

        followMap[followerId].insert(followeeId);
    }
    

    void unfollow(int followerId, int followeeId) {

        if(followerId == followeeId) return;

        followMap[followerId].erase(followeeId);
    }
};