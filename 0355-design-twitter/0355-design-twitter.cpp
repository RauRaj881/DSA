class Twitter {
public:
unordered_map<int,unordered_set<int>> following;
unordered_map<int,vector<pair<int,int>>> tweets;
int time=0;
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId){
        tweets[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId){
        vector<int> ans;
        vector<int> users;
        users.push_back(userId);
        for(auto it:following[userId]){
            users.push_back(it);
        }
        priority_queue<vector<int>> pq;
        for(int i=0;i<users.size();i++){
            //for(auto it:tweets[users[i]]){
            vector<pair<int,int>> it=tweets[users[i]];
                int sz=it.size();
                if(sz>0)pq.push({it[sz-1].first,it[sz-1].second,users[i],sz-1});
            //}
        }
        while(!pq.empty()&&ans.size()<10){
            vector<int> cr=pq.top();
            pq.pop();
            ans.push_back(cr[1]);
            int idx=cr[3],u=cr[2];
            if(idx-1>=0){
                pq.push({tweets[u][idx-1].first,tweets[u][idx-1].second,u,idx-1});
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId){
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId){
        following[followerId].erase(followeeId);
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