class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        int x=1;
        unordered_set<string> u;
        for(int i=0;i<wordList.size();i++){
            u.insert(wordList[i]);
        }
        if(u.find(endWord)==u.end()){return 0;}
        q.push({beginWord,x});
        while(!q.empty()){
            auto temp=q.front();
            string word=temp.first;
            int level=temp.second;
            q.pop();
            for(int i=0;i<word.size();i++){
                for(int j='a';j<='z';j++){
                    string curr=word;
                    curr[i]=j;
                    if(u.find(curr)!=u.end()){
                        q.push({curr,level+1});
                        u.erase(curr);
                    }
                   // else{curr=word;}
                    if(curr==endWord){return level+1;}
                }
            }
        }
        return 0;
    }
};