class Twitter {
public:
unordered_map<int,unordered_set<int>> fl;
unordered_map<int,vector<pair<int,int>>> twt;
int tm=0;
    Twitter() {
    }
    
    void postTweet(int uId,int tId){
        twt[uId].push_back({tId,tm});
        tm++;
    }
    
    vector<int> getNewsFeed(int uId){
        vector<int> users;
        users.push_back(uId);
        for(auto it:fl[uId]){
            users.push_back(it);
        }
        priority_queue<vector<int>> pq;
        for(int i=0;i<users.size();i++){
            int sz=twt[users[i]].size();
            vector<pair<int,int>>& tp=twt[users[i]];
            if(sz>0){
                pq.push({tp[sz-1].second,tp[sz-1].first,users[i],sz-1});
            }
        }
        vector<int> ans;
        while(!pq.empty()&&ans.size()<10){
            vector<int> tp=pq.top();
            pq.pop();
            int u=tp[2],idx=tp[3];
            ans.push_back(tp[1]);
            if(idx-1>=0){
                pq.push({twt[u][idx-1].second,twt[u][idx-1].first,u,idx-1});
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId){
        fl[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId){
        fl[followerId].erase(followeeId);
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