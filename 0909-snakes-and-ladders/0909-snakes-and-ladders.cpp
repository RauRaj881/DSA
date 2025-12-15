class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        queue<int> q;
        vector<bool> visited(n*n + 1, false);
        q.push(1);
        visited[1]=1;
        int cnt=0;
        while(!q.empty()){
            cnt++;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int temp=q.front();
                q.pop();
                for(int j=1;j<=6;j++){
                    int num=temp+j;
                    if (num > n*n) continue;
                    if(num==n*n){return cnt;}
                    int curr=num-1;
                    int nextr,nextc;
                    nextr=n-(curr/n)-1;
                    if((curr/n)%2==0){
                        nextc=curr%n;
                    }
                    else{
                        nextc=n-curr%n-1;
                    }
                    int dest = (board[nextr][nextc] == -1)
                               ? num
                               : board[nextr][nextc];

                    if(dest == n*n) return cnt;
                    if(!visited[dest]){
                        visited[dest] = true;
                        q.push(dest);
                    }
                }
            }
        }
        return -1;
    }
};