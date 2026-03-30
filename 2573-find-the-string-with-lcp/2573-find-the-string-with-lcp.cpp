class Solution {
public:
    string findTheString(vector<vector<int>>& lcp){
        int n=lcp.size();
        string s(n, '\0');
        char current = 'a';
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i==j){if(lcp[i][j]!=n-i){return "";}}
                else if(lcp[i][j]!=lcp[j][i]){return "";}
                else if(lcp[i][j]>min(n-i,n-j)){return "";}
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '\0') {
                if (current > 'z') {
                    return "";
                }
                s[i] = current;
                for (int j = i + 1; j < n; j++) {
                    if (lcp[i][j] > 0) {
                        s[j] = s[i];
                    }
                }
                current++;
            }
        }
        for(int i=0;i<n-1;i++){
            for(int j=i;j<n;j++){
                string lt=s.substr(j,lcp[i][j]);
                string st=s.substr(i,lcp[i][j]);
                if(lt!=st||(j+lcp[i][j]<n&&s[i+lcp[i][j]]==s[j+lcp[i][j]])){return "";}
            }
        }
        return s;
    }
};